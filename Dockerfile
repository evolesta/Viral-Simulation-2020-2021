FROM mcr.microsoft.com/dotnet/sdk:3.1 AS dotnetsdk

FROM httpd:2.4 AS server


FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build


FROM dotnetsdk AS tester

WORKDIR /home/src/viralsimtester

COPY --from=builder /home/src/viralsim/ViralSimulation.SeleniumTests ./ViralSimulation.SeleniumTests
COPY --from=builder /home/src/viralsim/build ../viralsim
COPY --from=builder /home/src/viralsim/runtest ./

SHELL ["/bin/bash", "-c"]
RUN ./runtest


FROM server AS final
WORKDIR /usr/local/apache2/htdocs/
RUN rm -rf ./*
COPY --from=tester /home/src/viralsim .


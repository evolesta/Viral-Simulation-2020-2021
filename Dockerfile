
FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS testbuilder
WORKDIR /home/src/viralsimtester
COPY --from=builder /home/src/viralsim/ViralSimulation.SeleniumTests ./ViralSimulation.SeleniumTests
COPY --from=builder /home/src/viralsim/build ../viralsim

# TODO: 
# SHELL commands in file (MAKE SURE IT EXISTS FIRST!):
# Capture $0 in variable, then log test results, then if statement. 
SHELL ["/bin/bash", "-c"]
# RUN cd ViralSimulation.SeleniumTests; dotnet test; if [ $? -ne 0 ]; then exit 1; fi 
RUN /runtest

FROM httpd:2.4 AS server
WORKDIR /usr/local/apache2/htdocs/
RUN rm -rf ./*
COPY --from=testbuilder /home/src/viralsim .


# Point at any base image that you find suitable to extend.


FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build

# FROM selenium/standalone-firefox:4.0.0-beta-4-20210608 AS tester

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS testbuilder
WORKDIR /home/src/viralsimtester
COPY --from=builder /home/src/viralsim/ViralSimulation.SeleniumTests ./ViralSimulation.SeleniumTests
COPY --from=builder /home/src/viralsim/build ../viralsim

 RUN cd ViralSimulation.SeleniumTests; dotnet test; if [ $? -ne 0 ]; then EXIT 1; fi 

 FROM httpd:2.4 AS testserver
 WORKDIR /usr/local/apache2/htdocs/
 RUN rm -rf ./*
 COPY --from=testbuilder /home/src/viralsim .


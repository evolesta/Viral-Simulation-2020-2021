# Point at any base image that you find suitable to extend.


FROM emscripten/emsdk:2.0.15 AS builder
WORKDIR /home/src/viralsim  
COPY . . 
RUN make prod-build

FROM httpd:2.4 AS testserver
WORKDIR /usr/local/apache2/htdocs/
COPY --from=builder /home/src/viralsim/build .

FROM selenium/standalone-firefox:4.0.0-beta-4-20210608 AS tester

FROM mcr.microsoft.com/dotnet/sdk:3.1 AS testbuilder
WORKDIR /home/src/viralsimtester
COPY --from=builder /home/src/viralsim/ViralSimulation.SeleniumTests ./ViralSimulation.SeleniumTests
COPY --from=builder /home/src/viralsim/build ../viralsim

# Install Chrome
 RUN apt-get update && apt-get install -y \
 apt-transport-https \
 ca-certificates \
 curl \
 gnupg \
 hicolor-icon-theme \
 libcanberra-gtk* \
 libgl1-mesa-dri \
 libgl1-mesa-glx \
 libpango1.0-0 \
 libpulse0 \
 libv4l-0 \
 fonts-symbola \
 --no-install-recommends \
 && curl -sSL https://dl.google.com/linux/linux_signing_key.pub | apt-key add - \
 && echo "deb [arch=amd64] https://dl.google.com/linux/chrome/deb/ stable main" > /etc/apt/sources.list.d/google.list \
 && apt-get update && apt-get install -y \
 google-chrome-stable \
 --no-install-recommends \
 && apt-get purge --auto-remove -y curl \
 && rm -rf /var/lib/apt/lists/*

#RUN cd ViralSimulation.SeleniumTests; dotnet test; if [ $? -ne 0 ]; then rm -rf /home/src/viralsim/*; fi 



#FROM testserver AS final
#RUN rm -rf ./*
#COPY --from=testbuilder /home/src/viralsim .


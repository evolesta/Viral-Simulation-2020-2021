FROM emscripten/emsdk AS compiler

WORKDIR /home/src
RUN git clone https://github.com/evolesta/Viral-Simulation-2020-2021.git
WORKDIR /home/src/Viral-Simulation-2020-2021
RUN git switch Docker
RUN make prod-build

FROM httpd AS webserver
WORKDIR /usr/local/apache2/htdocs/
COPY --from=compiler /home/src/Viral-Simulation-2020-2021/build .
#FROM debian:stretch
FROM ubuntu:18.04
LABEL maintainer="The Luxcore Developers <giaki3003@Luxcore.io>"
LABEL description="Dockerised Luxcore, built from Travis"

RUN apt-get update && apt-get install -y software-properties-common unzip
RUN apt-get install -y wget

RUN wget https://github.com/LUX-Core/Lux/releases/download/v5.2.3/Lux-qt-linux-18.zip
RUN unzip Lux-qt-linux-18.zip
RUN cp Luxd /usr/local/bin

VOLUME ["/opt/Lux"]

EXPOSE 9888
EXPOSE 9888
EXPOSE 9777
EXPOSE 9777

CMD ["Luxd", "--conf=/opt/Lux/Lux.conf", "--printtoconsole"]
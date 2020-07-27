#FROM debian:stretch
FROM ubuntu:18.04
LABEL maintainer="The Astracore Developers <giaki3003@astracore.io>"
LABEL description="Dockerised Astracore, built from Travis"

RUN apt-get update && apt-get install -y software-properties-common unzip
RUN apt-get install -y wget

RUN wget https://github.com/ASTRA-Core/astra/releases/download/v5.2.3/astra-qt-linux-18.zip
RUN unzip astra-qt-linux-18.zip
RUN cp astrad /usr/local/bin

VOLUME ["/opt/astra"]

EXPOSE 9888
EXPOSE 9888
EXPOSE 9777
EXPOSE 9777

CMD ["astrad", "--conf=/opt/astra/astra.conf", "--printtoconsole"]
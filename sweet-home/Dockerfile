FROM ubuntu
MAINTAINER HexRabbit ashlerhex@ccns.ncku.edu.tw

RUN sed -i 's/http:\/\/archive/http:\/\/tw.archive/g' /etc/apt/sources.list \
  && apt-get update \
  && apt-get install -y --no-install-recommends \
  g++ \
  gcc \
  nmap \
  && useradd sweet-home \
  && mkdir /home/sweet-home \
  && chown root:sweet-home /home/sweet-home \
  && chmod 750 /home/sweet-home 

COPY main.c /home/sweet-home
COPY flag /home/sweet-home

RUN cd /home/sweet-home \
  && gcc main.c -fPIE -pie \
  && rm main.c

EXPOSE 4000

USER sweet-home

CMD ncat -vc /home/sweet-home/a.out -kl 0.0.0.0 4000

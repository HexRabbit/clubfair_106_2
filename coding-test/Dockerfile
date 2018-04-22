FROM ubuntu
MAINTAINER HexRabbit ashlerhex@ccns.ncku.edu.tw

RUN sed -i 's/http:\/\/archive/http:\/\/tw.archive/g' /etc/apt/sources.list \
  && apt-get update \
  && apt-get install -y --no-install-recommends \
  g++ \
  gcc \
  nmap \
  && useradd coding-test \
  && mkdir /home/coding-test \
  && chown root:coding-test /home/coding-test \
  && chmod 750 /home/coding-test 

COPY main.c /home/coding-test
COPY flag /home/coding-test

RUN cd /home/coding-test \
  && gcc main.c -fPIE -pie -z execstack \
  && rm main.c

EXPOSE 4000
USER coding-test
CMD ncat -vc /home/coding-test/a.out -kl 0.0.0.0 4000

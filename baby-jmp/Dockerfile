FROM ubuntu
MAINTAINER HexRabbit ashlerhex@ccns.ncku.edu.tw

RUN sed -i 's/http:\/\/archive/http:\/\/tw.archive/g' /etc/apt/sources.list \
  && apt-get update \
  && apt-get install -y --no-install-recommends \
  g++ \
  gcc \
  nmap \
  && useradd baby-jmp \
  && mkdir /home/baby-jmp \
  && chown root:baby-jmp /home/baby-jmp \
  && chmod 750 /home/baby-jmp 

COPY main.c /home/baby-jmp
COPY flag /home/baby-jmp

RUN cd /home/baby-jmp \
  && gcc main.c -fno-stack-protector

EXPOSE 4000

USER baby-jmp

CMD ncat -vc /home/baby-jmp/a.out -kl 0.0.0.0 4000

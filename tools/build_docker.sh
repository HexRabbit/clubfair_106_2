if [ -z $1 ] || [ -z $2 ]; then
  echo "Usage: ./build_docker.sh <USER> <CFLAGS>"
  exit 0
fi

USER=$1
CFLAGS=$2

echo "\
FROM ubuntu
MAINTAINER HexRabbit ashlerhex@ccns.ncku.edu.tw

RUN sed -i 's/http:\/\/archive/http:\/\/tw.archive/g' /etc/apt/sources.list \\
  && apt-get update \\
  && apt-get install -y --no-install-recommends \\
  g++ \\
  gcc \\
  nmap \\
  && useradd $USER \\
  && mkdir /home/$USER \\
  && chown root:$USER /home/$USER \\
  && chmod 750 /home/$USER 

COPY main.c /home/$USER
COPY flag /home/$USER

RUN cd /home/$USER \\
  && gcc main.c $CFLAGS \\
  && rm main.c

EXPOSE 4000

USER $USER

CMD ncat -vc /home/$USER/a.out -kl 0.0.0.0 4000
" > Dockerfile

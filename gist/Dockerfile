FROM ubuntu:14.04
ENV INSTALL apt-get -y install
RUN apt-get update&&apt-get -y upgrade&&$INSTALL apt-utils
RUN $INSTALL curl wget build-essential emacs24-nox tree
WORKDIR /root
EXPOSE 80 443
ENV QQ YY
ENV xx ww
VOLUME /ext
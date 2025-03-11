# используем новейшую версию убунту
FROM ubuntu:latest

# метаданные
LABEL maintainer="Ilya <ilya.email@example.com>"
ENV LOGNAME="root"
ENV USER="rootuser"

# Установка зависимостей
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gcc \
    make \
    debhelper \
    dh-make \
    && rm -rf /var/lib/apt/lists/* 

# Копируем файлы в контейнер
COPY ./src/bubbleSort.c ./src/makefile /app/

# Устанавливаем рабочую директорию
WORKDIR /app

RUN dh_make --native -s -p bubblesort_1.0 -y
RUN dpkg-buildpackage -us -uc
RUN sudo dpkg -i bubblesort_1.0_amd64.deb

CMD ["/usr/bin/bubbleSort"]

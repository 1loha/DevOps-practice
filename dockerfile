# используем новейшую версию убунту
FROM ubuntu:latest

# метаданные
LABEL maintainer="Ilya <ilya.email@example.com>"

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

# Собираем проект
CMD ["make"]

# Запускаем тесты
CMD ["make test"]

CMD ["make package"]

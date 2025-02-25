CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = bubbleSort
SRC = bubbleSort.c
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
# Очистка (удаление скомпилированного файла)
clean:
	rm -f $(TARGET)
# Правило для пересборки
rebuild: clean all

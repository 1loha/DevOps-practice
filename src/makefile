CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
TARGET = bubbleSort
SRC = bubbleSort.c
BINDIR = $(CURDIR)/../usr/bin

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -o $(BINDIR)/$(TARGET) $(SRC)

clean: 
	rm -f $(BINDIR)/$(TARGET)
	rm -r $(CURDIR)/../usr

test: $(TARGET)
	@echo "\n\n\t\tRunning tests"
	@echo "\n\tСhecking the array size"

	@echo "Test 1. positive number"
	@echo "3\n3\n1\n2\n" | $(BINDIR)/$(TARGET) | grep -q "1 2 3" && echo "PASSED" || echo "FAILED"

	@echo "Test 2. Invalid size (negative number)"
	@echo "-5\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid size" && echo "PASSED" || echo "FAILED"

	@echo "Test 3. Invalid size (not an integer)"
	@echo "4.5\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid size" && echo "PASSED" || echo "FAILED"

	@echo "Test 4. Invalid size (zero)"
	@echo "0\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid size" && echo "PASSED" || echo "FAILED"

	@echo "Test 5. Invalid input (non-numeric)"
	@echo "abc\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid size" && echo "PASSED" || echo "FAILED"

	@echo "\n\tСhecking array elements"

	@echo "Test 6. array with a positive number"
	@echo "3\n24\n12\n25\n" | $(BINDIR)/$(TARGET) | grep -q "12 24 25" && echo "PASSED" || echo "FAILED"

	@echo "Test 7. array with an zero"
	@echo "3\n0\n2\n0\n" | $(BINDIR)/$(TARGET) | grep -q "0 0 2" && echo "PASSED" || echo "FAILED"

	@echo "Test 8. array with a negative numbers"
	@echo "4\n3\n-1\n2\n-3\n" | $(BINDIR)/$(TARGET) | grep -qe "-3 -1 2 3" && echo "PASSED" || echo "FAILED"

	@echo "Test 9. Array with non-numeric elements"
	@echo "5\n3\n1\n2\ndns\n1\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid input" && echo "PASSED" || echo "FAILED"

	@echo "Test 10. Array with non-integers"
	@echo "3\n42\n-3.3\n1.0\n" | $(BINDIR)/$(TARGET) 2>&1 | grep -q "Invalid input" && echo " PASSED" || echo : "FAILED"

package:
	sudo apt install -y debhelper dh-make build-essential
	dh_make --native -s -p -y bubbleSort
	dpkg-buildpackage -us -uc

rebuild: 
	clean all

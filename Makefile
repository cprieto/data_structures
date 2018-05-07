INCLUDE=include
OUTPUT=output
SOURCES=$(wildcard src/*.c)
TESTS=$(wildcard tests/*.c)

$(OUTPUT):
	mkdir -p $(OUTPUT)

libds.o: $(SOURCES) $(OUTPUT)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $(OUTPUT)/libds.o

libds.a: libds.o
	ar rcs $(OUTPUT)/libds.a $(OUTPUT)/libds.o

test: $(TESTS) libds.a
	$(CC) -o $(OUTPUT)/all_tests -I$(INCLUDE) $< -lcriterion $(OUTPUT)/libds.a
	$(OUTPUT)/all_tests

clean:
	rm -rf $(OUTPUT)

all: libds.a

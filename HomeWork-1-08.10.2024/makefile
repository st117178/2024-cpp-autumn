TARGET = HomeWork_1
CC = g++

PREF_SRC = ./src/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: $(PREF_SRC)%.cpp
	$(CC) -c $< -o $@

clean:
	rm $(TARGET) *.o
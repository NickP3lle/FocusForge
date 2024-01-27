# Makefile per compilare main.cpp, task.cpp, toDo.cpp su Mac con processore ARM

CXX = c++        # Compilatore C++ per architettura ARM64 (versione 11 o successiva)
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic  # Opzioni del compilatore con C++17

# Nome dell'eseguibile
TARGET = main.out

# Lista dei file sorgente
SRCS = main.cpp task.cpp toDo.cpp

# Lista dei file header
HEADERS = task.h toDo.h

# Lista dei file oggetto generati dalla compilazione
OBJS = $(SRCS:.cpp=.o)

# Regola per la compilazione dell'eseguibile
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regola per la compilazione dei file oggetto
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(OBJS) $(TARGET)

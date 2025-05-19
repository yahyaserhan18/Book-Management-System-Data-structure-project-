# Derleme sonrası oluşacak çalıştırılabilir dosya adı
TARGET = BookApp

# Derleyici
CXX = g++

# Ana kaynak dosyası (.cpp)
SRCS = BookManagementSystem.cpp

# Oluşacak nesne dosyası (.o)
OBJS = $(SRCS:.cpp=.o)

# Derleyici seçenekleri
CXXFLAGS = -std=c++11 -Wall

# Varsayılan hedef (make yazıldığında çalışacak olan)
all: $(TARGET)

# Çalıştırılabilir dosyanın nasıl oluşturulacağı
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# .cpp dosyasından .o dosyası oluşturma kuralı
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Geçici dosyaları silmek için temizlik komutu
clean:
	rm -f $(OBJS) $(TARGET)

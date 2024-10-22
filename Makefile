# Build for vector_angle

.PHONY: all
all : vector_angle dotProductTest

vector_angle : VectorAngle.o dotProduct.o
	g++ -std=c++17 $^ -o $@

VectorAngle.o : VectorAngle.cpp dotProduct.hpp
	g++ -std=c++17 -c $<

dotProduct.o : dotProduct.cpp dotProduct.hpp
	g++ -std=c++17 -c $<

dotProductTest : dotProductTest.o dotProduct.o
	g++ -std=c++17 $^ -o $@

dotProductTest.o : dotProductTest.cpp dotProduct.hpp
	g++ -std=c++17 -c $<

.PHONY: run
run : vector_angle
	./vector_angle "1.0,2.0,3.0" "4.0,5.0,6.0"

.PHONY: test
test : dotProductTest
	./dotProductTest

.PHONY: clean
clean : 
	@rm -f vector_angle VectorAngle.o dotProduct.o dotProductTest dotProductTest.o

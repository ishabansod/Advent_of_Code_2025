CXX = g++
CXXFLAGS = -Iinclude #-std=c++17

# Build usage: "make day01"
day%: src/day%.cpp
	$(CXX) $(CXXFLAGS) $< -pg -g -o $@

clean:
	rm -f day*
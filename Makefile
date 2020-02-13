TARGET = Group_Generator_v1.0
LIBS = -lm #Math Library, just a placeholder
HEADERS = Member.h MemberList.h Groups.h GroupsList.h
SRCS = Interface.cpp Member.cpp MemberList.cpp Groups.cpp GroupsList.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SRCS))
CXX = g++
CXX_FLAGS = #C++11 just for reference, not necessary

.PHONY: default all clean

all: depend $(TARGET)

#Rules to recompile template headers when they change
depend: .depend
.depend: $(HEADERS)
	rm -f ./.depend
	$(CXX) $(CXX_FLAGS) -MM $^ > ./.depend;
include .depend

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f ./.depend
	-rm -f $(TARGET)

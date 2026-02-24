NAME := test

SRCS := \
	main.cpp \
	Bureaucrat.cpp \

CXX := c++
CPPFLAGS := -MMD -MP
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g

OBJDIR := obj
OBJS := $(SRCS:%.cpp=$(OBJDIR)/%.o)
.SECONDARY: $(OBJS)

all: $(NAME)
clean:
	rm -rf $(OBJDIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
.DEFAULT_GOAL := all

$(OBJS): $(OBJDIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

DEPS = $(OBJS:.o=.d)
-include $(DEPS)

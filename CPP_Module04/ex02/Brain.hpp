
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define MAX_IDEA 100

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& brain);
		~Brain(void);
		Brain&	operator=(const Brain& brain);

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;

	private:
		std::string	_ideas[100];
};

#endif
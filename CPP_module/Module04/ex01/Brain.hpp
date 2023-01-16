#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>
#define IDEA_NUM 100

class Brain
{

	private:
		std::string ideas[IDEA_NUM];

	public:
		Brain(void);
		Brain(const Brain& obj);
		Brain& operator = (const Brain& obj);
		~Brain(void);

		void setIdea(const int pri_order, std::string ideaInMind);
		std::string getIdea(const int pri_order) const;
		void brain_scan(void);

};
std::ostream& operator<<(std::ostream& o, const Brain& b);

#endif /* BRAIN_H */

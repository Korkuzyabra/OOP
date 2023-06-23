#include <iostream>
#include <vector>

class character
{
public:
	std::string name;
	std::string birthday;
	std::string gender;
	std::string persanality;
	std::string type;
	std::string island;
};

class animals;
class person : public character
{
	friend std::string frendship_with_person(person, animals);
public:
	std::string hair;
	std::string eyes;
	std::string skin;
    int GetSkills()
    {
        return skills = rand() % 101;
    }
private:
	int skills;
	int frendlevel = 76;
};

class animals : public character
{
	friend std::string frendship_with_person(person, animals);
public:
	int popularity;
	std::string home;
	std::string HowHome(animals object)
	{
		if (persanality == "Normal")
			return object.home = "Antique setting";
		if (persanality == "Jock")
			return object.home = "Cute setting";
		if (persanality == "Lazy")
			return object.home = "Rattan setting";
		if (persanality == "Snooty")
			return object.home = "Asian setting";
	}
	bool operator<(const animals& object)
	{
		return object.popularity > popularity;
	}
	bool operator>(const animals& object)
	{
		return object.popularity < popularity;
	}
	bool operator==(const animals& object)
	{
		return object.rarity == rarity;
	}
	std::string rarity;
	animals operator=(std::string object)
	{
		this->island = object;
		return*this;
	}
private:
	int frendship = rand() % 101;
};

std::string frendship_with_person(person object, animals object1)
{
	if (object.frendlevel>= object1.frendship)
		return " are frends";
	else
		return "s aren't frends";
}

class Table
{
public:
    virtual void info() = 0;
    virtual ~Table() {}
};

class Chair
{
public:
    virtual void info() = 0;
    virtual ~Chair() {}
};

class Carpert
{
public:
    virtual void info() = 0;
    virtual ~Carpert() {}
};

class PersonTable : public Table
{
public:
    void info()
    {
        std::cout << "+stadart table" << std::endl;
    }
};

class PersonChair : public Chair
{
public:
    void info()
    {
        std::cout << "+green chair" << std::endl;
    }
};

class PersonCarpert : public Carpert
{
public:
    void info()
    {
        std::cout << "+brown carpert" << std::endl;
    }
};

class AnimalTable : public Table
{
public:
    void info()
    {
        std::cout << "+green table" << std::endl;
    }
};

class AnimalChair : public Chair
{
public:
    void info()
    {
        std::cout << "+pink chair" << std::endl;
    }
};

class AnimalCarpert : public Carpert
{
public:
    void info()
    {
        std::cout << "+standart carpert" << std::endl;
    }
};

class FurnitureFactory
{
public:
    virtual Table* createTable() = 0;
    virtual Chair* createChair() = 0;
    virtual Carpert* createCarpert() = 0;
    virtual ~FurnitureFactory() {}
};

class PersonFurnitureFactory : public FurnitureFactory
{
public:
    Table* createTable()
    {
        return new PersonTable;
    }
    Chair* createChair()
    {
        return new PersonChair;
    }
    Carpert* createCarpert()
    {
        return new PersonCarpert;
    }
};

class AnimalFurnitureFactory : public FurnitureFactory
{
public:
    Table* createTable()
    {
        return new AnimalTable;
    }
    Chair* createChair()
    {
        return new AnimalChair;
    }
    Carpert* createCarpert()
    {
        return new AnimalCarpert;
    }
};

class Furniture
{
public:
    ~Furniture()
    {
        int i;
        for (i = 0; i < vi.size(); ++i)  delete vi[i];
        for (i = 0; i < va.size(); ++i)  delete va[i];
        for (i = 0; i < vh.size(); ++i)  delete vh[i];
    }
    void info()
    {
        int i;
        for (i = 0; i < vi.size(); ++i)  vi[i]->info();
        for (i = 0; i < va.size(); ++i)  va[i]->info();
        for (i = 0; i < vh.size(); ++i)  vh[i]->info();
    }
    std::vector<Table*> vi;
    std::vector<Chair*> va;
    std::vector<Carpert*> vh;
};

class Craft
{
public:
    Furniture* createFurniture(FurnitureFactory& factory)
    {
        Furniture* p = new Furniture;
        p->vi.push_back(factory.createTable());
        p->va.push_back(factory.createChair());
        p->vh.push_back(factory.createCarpert());
        return p;
    }
};

class Flowers
{
public:
    void info() {
        std::cout << "Flowers planted" << std::endl;
    }
};

class Path
{
public:
    void info() {
        std::cout << "Path is laid" << std::endl;
    }
};

class Bridge
{
public:
    void info() {
        std::cout << "Bridge is laid" << std::endl;
    }
};

class Stone
{
public:
    void info() {
        std::cout << "Stone is broke" << std::endl;
    }
};

class Tree
{
public:
    void info() {
        std::cout << "Tree planted" << std::endl;
    }
};

class Island
{
public:
    std::vector<Flowers>  vi;
    std::vector<Path>     va;
    std::vector<Bridge>   vh;
    std::vector<Stone>    vc;
    std::vector<Tree>     ve;
    void info() {
        int i;
        for (i = 0; i < vi.size(); ++i)  vi[i].info();
        for (i = 0; i < va.size(); ++i)  va[i].info();
        for (i = 0; i < vh.size(); ++i)  vh[i].info();
        for (i = 0; i < vc.size(); ++i)  vc[i].info();
        for (i = 0; i < ve.size(); ++i)  ve[i].info();
    }
};

class IslandBuilder
{
protected:
    Island* p;
public:
    IslandBuilder() : p(0) {}
    virtual ~IslandBuilder() {}
    virtual void createIsland() {}
    virtual void buildFlower() {}
    virtual void buildPath() {}
    virtual void buildBridge() {}
    virtual void buildStone() {}
    virtual void buildTree() {}
    virtual Island* getIsland() { return p; }
};

class KinanaBuilder : public IslandBuilder
{
public:
    void createIsland() { p = new Island; }
    void buildFlower() { p->vi.push_back(Flowers()); }
    void buildPath() { p->va.push_back(Path()); }
    void buildBridge() { p->vh.push_back(Bridge()); }
    void buildStone() { p->vc.push_back(Stone()); }
};

class AnotherBuilder : public IslandBuilder
{
public:
    void createIsland() { p = new Island; }
    void buildFlowers() { p->vi.push_back(Flowers()); }
    void buildPath() { p->va.push_back(Path()); }
    void buildBridge() { p->vh.push_back(Bridge()); }
    void buildTree() { p->ve.push_back(Tree()); }
};

class Director
{
public:
    Island* createIsland(IslandBuilder& builder)
    {
        builder.createIsland();
        builder.buildFlower();
        builder.buildPath();
        builder.buildBridge();
        builder.buildStone();
        builder.buildTree();
        return(builder.getIsland());
    }
};

std::vector inventory{"ax", "net", "fishing rod", "rose", "shovel"};
std::vector treeKinana{"peach", "orange", "coconut"};
std::vector treeAnother{"apple", "pear", "cherry", "coconut"};

const bool is_human = true;
const bool is_not_human = false;
using Type1 = std::conditional<is_human, person, animals>::type;
using Type2 = std::conditional<is_not_human, person, animals>::type;

template <typename T>
concept luck_t = std::same_as<T, int> || std::same_as<T, double>;
template <luck_t T>
T luck(T a, T b) { return a + b; }

constexpr int pop(int a, int b)
{
    return a + b;
}

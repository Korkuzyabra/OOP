//Паттерны: декоратор, адаптер, стратегия
class Program
{
    static void Main(string[] args)
    {
        Cake cake1 = new HoneyCake();
        cake1 = new BerryCake(cake1);
        Console.WriteLine("Name: {0}", cake1.Name);
        Console.WriteLine("Cost: {0}", cake1.GetCost());

        Cake cake2 = new HoneyCake();
        cake2 = new NutCake(cake2);
        Console.WriteLine("Name: {0}", cake2.Name);
        Console.WriteLine("Cost: {0}", cake2.GetCost());

        Cake cake3 = new MousseCake();
        cake3 = new BerryCake(cake3);
        cake3 = new NutCake(cake3);
        Console.WriteLine("Name: {0}", cake3.Name);
        Console.WriteLine("Cost: {0}", cake3.GetCost());

        Console.WriteLine(" ");

        Human human = new Human();
        Food food = new Food();
        human.Eat(food);
        HDiet cake1Diet = new CakeToDietAd(cake1);
        human.Eat(cake1Diet);
    }

    abstract class Cake
    {
        public Cake(string n)
        {
            this.Name = n;
        }
        public string Name { get; protected set; }
        public abstract int GetCost();
        public void sugar()
        {
            Console.WriteLine("Cake without sugar");
        }
    }

    class HoneyCake : Cake
    {
        public HoneyCake() : base("Honney cake")
        { }
        public override int GetCost()
        {
            return 8;
        }
    }

    class MousseCake : Cake
    {
        public MousseCake() : base("Mousse cake")
        { }
        public override int GetCost()
        {
            return 10;
        }
    }

    abstract class Dcake : Cake
    {
        protected Cake cake;
        public Dcake(string n, Cake cake) : base(n)
        {
            this.cake = cake;
        }
    }

    class BerryCake : Dcake
    {
        public BerryCake(Cake p) : base (p.Name + ", with berry", p)
        { }
        public override int GetCost()
        {
            return cake.GetCost() + 5;
        }
    }

    class NutCake : Dcake
    {
        public NutCake(Cake p) : base(p.Name + ", with nuts", p)
        { }
        public override int GetCost()
        {
            return cake.GetCost() + 8;
        }
    }

    interface HDiet
    {
        void fit();
    }

    class Food : HDiet
    {
        public void fit()
        {
            Console.WriteLine("Man following a diet");
        }
    }

    class Human
    {
        public void Eat(HDiet Diet)
        {
            Diet.fit();
        }
    }

    interface DCake
    {
        void sugar();
    }
    class CakeToDietAd : HDiet
    {
        Cake cake;
        public CakeToDietAd(Cake c)
        {
            cake = c;
        }
        public void fit()
        {
            cake.sugar();
        }
    }

}

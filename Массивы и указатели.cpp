#include <iostream>

int main()
{
    setlocale(0, "rus");
    int N; bool b;
    do {
        std::cout << "Введите кол-во строк: " << std::endl;// Вводим кол-во строк
        if ((std::cin >> N).good());
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (N < 1);

    int M;
    std::cout << "Введите кол-во столбцов: ";// Вводим кол-во столбцов
    do 
    {
        if ((std::cin >> M).good());
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (M < 1);

    // Выделяем память под матрицу
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
        A[i] = new int[M];

    // Вводим элементы матрицы
    std::cout << "Введите матрицу:\n ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            do 
            {
                if ((std::cin >> A[i][j]).good());
                b = 0;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cout << "Неверный ввод, повторите.\n";
                    b = 1;
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } while (b != 0);
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int k = 0, x, y; k < M; k++)
        {
            int aMin = 0, aMax = 0;
            for (int i = 0; i < M; i++)
            {
                if (A[j][k] > A[j][i] || A[j][k] == A[j][i]) { aMax++; x = j; y = k; }
                else 
                {
                    aMax--; 
                }
            }
            if (aMax == M)
            {
                for (int i = 0; i < N; i++)
                {
                    if (A[x][y] < A[i][y] || A[x][y] == A[i][y]) 
                    { 
                        aMin++; 
                    }
                    else 
                    { 
                        aMin--; 
                    }
                }
                if (aMin == N) 
                { 
                    std::cout << " A[" << x + 1 << "][" << y + 1 << "] = " << A[x][y] << " седловая точка\n"; 
                }
            }
            else
            {
                int aMin = 0, aMax = 0;
                for (int i = 0; i < M; i++)
                {
                    if (A[x][y] < A[x][i] || A[x][y] == A[x][i]) 
                    { 
                        aMin++; 
                    }
                    else 
                    { 
                        aMin--; 
                    }
                }
                if (aMin == M)
                {
                    for (int i = 0; i < N; i++)
                    {
                        if (A[x][y] > A[i][y] || A[x][y] == A[i][y]) 
                        { 
                            aMax++; 
                        }
                        else 
                        { 
                            aMax--; 
                        }
                    }
                    if (aMax == N) 
                    {
                        std::cout << " A[" << x + 1 << "][" << y + 1 << "] = " << A[x][y] << " седловая точка\n"; 
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;
    return 0;
}

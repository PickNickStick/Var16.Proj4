#include <conio.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void matrix_sort(int **mas,int n,int m)
{
    int offset,buffer,i,j,k;
    for(i=0; i<n; i++)
    {
        offset=0;
        for(j=0;j<m;j++)
            while(true)
            {
                if(mas[i][j]!=0 || (j > m-offset-1)) break;
                for(k=j; k<(m-offset-1); k++)
                {
                    buffer = mas[i][k];
                    mas[i][k]= mas[i][k+1];
                    mas[i][k+1] = buffer;
                }
                offset++;
            }
    }
}

int main()
{
    ifstream fin;
    int  m, n, i, j;
    cout<<"Reading file..."<<endl;
    fin.open("in.txt");
    if(fin.fail())
    {
        cout<<"No such file, programm aborted."<<endl;
        return 1;
    }
    fin >> n >> m;
    int **mas = new int*[n];
    for(i = 0; i < n; i++)
        mas[i] = new int[m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            fin >> mas[i][j];
    }
    fin.close();
    cout<<"Done!\nSorting..."<<endl;
    matrix_sort(mas,n,m);
    cout<<"Done!\nSaving results..."<<endl;
    ofstream fout;
    fout.open("out.txt");
    if(fout.fail())
    {
        cout<<"Can't create output file, programm aborted.";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        fout << endl;
        for (int j = 0; j < m; j++)
            fout << mas[i][j] << '\t';
    }
    fout.close();
    cout<<"Done!\nProcess completed, press any key to continue...";
    _getch();
    return 0;
}

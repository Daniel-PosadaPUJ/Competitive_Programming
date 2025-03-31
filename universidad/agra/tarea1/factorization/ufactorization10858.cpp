/*
10858 UVa Solution (Unique Factorization)
Daniel Alejandro Posada Noguera
09 de Septiembre del 2024
*/

#include <iostream>
#include <vector> 
#include <stack>
#include <cmath>

using namespace std;

void printStack(stack<int> &factors){
    stack<int> factorsAux;
    while(!factors.empty()){
        factorsAux.push(factors.top());
        factors.pop();
    }
    while(!factorsAux.empty()){
      	cout << factorsAux.top();
      	factors.push(factorsAux.top());
      	factorsAux.pop();
      	if(!factorsAux.empty())
         	cout << " ";
    }
    cout << endl;
}

void printSolutions(vector<stack<int>> &lFactors){
	int n = lFactors.size(), i;
    cout << n << endl;
	for(i = 0; i < n; i++)
		printStack(lFactors[i]);
}

vector<int> getFactors(int N){
    int i, n = N/2;
    vector<int> factors;
    for(i = 2; i <= n; i++){
        if(N % i == 0){
            factors.push_back(i);
        }
    }
    return factors;
}

int assignValueStack(stack<int> &s){
    int ans = s.top();
    s.pop();
    return ans;
}

/* 
INTENTO DE FACTORIZATION SIN RECURSIÓN CON UN MÉTODO DIFERENTE

void factorizations(int N, vector<stack<int>> &lFactors){
    int i = 0, n = N;
    vector<int> factors = getFactors(N);
    stack<int> factorization, stRecursion;

    while(i < factors.size() || !stRecursion.empty()){
        if(n == 1 && !factorization.empty()){
            lFactors.push_back(factorization);
            factorization.pop();
            if(!stRecursion.empty()){
                i = assignValueStack(stRecursion);
                n = assignValueStack(stRecursion);
            }
        }
        else if(n >= factors[i]){
            if(n % factors[i] == 0){
                factorization.push(factors[i]);
                if(n != factors[i]){
                    stRecursion.push(i);
                    stRecursion.push(n);
                }
                n /= factors[i];
                i -= 1;
            }
        }
        else{
            n = assignValueStack(stRecursion);
            i = assignValueStack(stRecursion);
        }
        i++;
    }

}
*/

void factorizations(int N, vector<stack<int>> &lFactorizations){
    vector<int> factors = getFactors(N);
    stack<int> factorization, stRecursion;
    int i = 0, n = N, factor, coFactor;
    bool timeForChange = false;

    while(i < factors.size() || !stRecursion.empty()){
        if (i < factors.size()){
            factor = factors[i];
        }
        else{
            timeForChange = true;
        }
        if(n == 1){
            lFactorizations.push_back(factorization);
            timeForChange = true;
        }
        timeForChange = timeForChange || (factor > n);
        if(timeForChange){
            factorization.pop();
            if(!stRecursion.empty()){
                n = assignValueStack(stRecursion);
                i = assignValueStack(stRecursion);
            }
            factor = factors[i];
            timeForChange = false;
        }
        if(n % factor == 0){
            coFactor = n/factor;
            factorization.push(factor);
            stRecursion.push(i + 1);
            stRecursion.push(n);
            n = coFactor;
            i -= 1;
        }
        timeForChange = timeForChange || (i + 1 == factors.size()) && !stRecursion.empty();
        i = (i + 1 == factors.size()) ? i : i + 1;
        cout << "(" << i << " " << n << " " << factor << ")" << endl;
        printStack(factorization);
    }
}

void factorization(int N, int lower, vector<stack<int>> &lFactors, stack<int> &factors){
    if(N == 1){
        if(factors.size() > 1)
            lFactors.push_back(factors);
    }
    else{
        int i;
        for(i = lower; i <= N; i++){
            if(N % i == 0){
                factors.push(i);
                factorization(N/i, i, lFactors, factors);
                factors.pop();
            }
        }
    }
}

int main(){
    int N;
    vector<stack<int>> lFactors;
    cin >> N;
    while(N){
        factorizations(N, lFactors);
        printSolutions(lFactors);
        lFactors.clear();
        cin >> N;
    }
    return 0;
}



#include <iostream>
#include "Cliente.h"
#include "CSVRead.h"
#include "PriorityQueue.h"
#include "TransformadorCSV.h"
#include "ArbolABB.h"
#include "IReader.h"
using namespace std;
int main() {

    IReader<Cliente*>* reader = new CsvReader<Cliente*>("personas.csv", new TransformadorCsvPersona());
    ArbolABB<Cliente*>* clientes = reader->leerTodos();

    for (auto& cliente : *clientes){
        cout << cliente->toString() << endl;
    }

    return 0;
}

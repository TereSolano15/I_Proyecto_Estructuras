#include <iostream>
#include "Cliente.h"
#include "CSVRead.h"
#include "CSVWriter.h"
#include "PriorityQueue.h"
#include "TransformadorCSV.h"
#include "ArbolABB.h"
#include "IReader.h"
using namespace std;
int main() {

    IReader<Cliente*>* reader = new CsvReader<Cliente*>("BancoUNO.csv", new TransformadorCsvCliente());
    ArbolABB<Cliente*>* clientes = reader->leerTodos();

    for (auto& cliente : *clientes){
        cout << cliente->toString() << endl;
    }

    delete clientes;
    delete reader;
}

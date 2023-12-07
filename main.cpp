#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void procedureTelaCadastro() {
  cout << endl;
  cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
  cout << "      Tela De Cadasto\n";
  cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
  cout << endl;
  cout << "1 - Cadastrar\n";
  cout << "2 - Relatório geral\n";
  cout << "3 - Relatório de contas a receber\n";
  cout << "4 - Relatório de contas vencidas \n";
  cout << "5 - Sair\n";
  cout << "Escolha a opção: ";
}

class Locacao {
public:
  Locacao(string uimovel, string ulocador, string uinquilino, string uendereco,
          int diaVencimento)
      : imovel(uimovel), locador(ulocador), inquilino(uinquilino),
        endereco(uendereco), diaVencimento(diaVencimento) {}

  void getCadastro() const {
    cout << endl;
    cout << "imovel: " << imovel << endl;
    cout << "locador: " << locador << endl;
    cout << "inquilino: " << inquilino << endl;
    cout << "endereco: " << endereco << endl;
    cout << "dia vencimento: " << diaVencimento << endl;
    cout << "____\n";
  };

  void getContaAReceber() const {
    // Obtém o tempo atual
    auto currentTime = std::chrono::system_clock::now();

    // Obtém a data atual
    auto currentDate = std::chrono::system_clock::to_time_t(currentTime);
    struct std::tm *timeInfo = std::localtime(&currentDate);

    // Extrai o número do dia atual
    int diaAtual = timeInfo->tm_mday;

    if (diaVencimento < diaAtual) {
      getCadastro();
    }
  }
void getContaVigente() const {
  // Obtém o tempo atual
  auto currentTime = std::chrono::system_clock::now();

  // Obtém a data atual
  auto currentDate = std::chrono::system_clock::to_time_t(currentTime);
  struct std::tm *timeInfo = std::localtime(&currentDate);

  // Extrai o número do dia atual
  int diaAtual = timeInfo->tm_mday;

  if (diaVencimento > diaAtual) {
    getCadastro();
  }
}

private:
  string imovel, locador, inquilino, endereco;
  int diaVencimento;
};

int main() {
  int resp;
  vector<Locacao> locacoes;
  do {
    procedureTelaCadastro();
    cin >> resp;
    cin.ignore();

    switch (resp) {
    case 1: {
      string imovel, locador, inquilino, endereco;
      int diaVencimento;
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      cout << "      CADASTRANDO         \n";
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      cout << "Digite o nome do imovel: ";
      getline(cin, imovel);
      cout << "Digite o nome do locador: ";
      getline(cin, locador);
      cout << "Digite o nome do inquilino: ";
      getline(cin, inquilino);
      cout << "Digite o endereço: ";
      getline(cin, endereco);

      do {
        cout << "Digite o dia de vencimento (numeral): ";
        cin >> diaVencimento;
      } while (diaVencimento < 1 || diaVencimento > 31);

      locacoes.push_back(
          Locacao(imovel, locador, inquilino, endereco, diaVencimento));
      cout << "Usuário cadastrado com sucesso!\n";
      cout << endl;
      break;
    }
    case 2: {
      cout << endl;
      cout << endl;
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      cout << "  RELATÓRIO DE CONTAS     \n";
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      for (const auto &locacao : locacoes) {
        locacao.getCadastro();
        cout << endl;
      }
      break;
    }
    case 3: {
      cout << endl;
      cout << endl;
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      cout << "CONTAS VIGENTES\n";
      cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
      for (const auto &locacao : locacoes) {
        locacao.getContaVigente();
        cout << endl;
      }
      break;
    }
    case 4: {
        cout << endl;
        cout << endl;
        cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
        cout << "CONTAS VENCIDAS\n";
        cout << "=-=-=-=-=-=-==-=-=-=-=-=-=\n";
        for (const auto &locacao : locacoes) {
          locacao.getContaAReceber();
          cout << endl;
        }



        break;
      }
    case 5: {
      cout << "Saindo...";
      break;
    }
    default: {
      cout << "Opção inválida\n";
      break;
    }
    }

  } while (resp != 5);

  return 0;
}

#include <vector>
#include <iterator>
#include <string>
#include <iostream>

class bolsaChuches
{
private:
    std::vector<std::string> chuches = {};

    ~bolsaChuches()
    {
        this->chuches.clear();
    }

public:
    bolsaChuches(std::vector<std::string> chuchesBastanteMajas = {})
    {
        for (std::vector<std::string>::iterator itChuches = chuchesBastanteMajas.begin(); itChuches != chuchesBastanteMajas.end(); ++itChuches)
        {
            this->chuches.push_back(*itChuches);
        }
    }

    friend void mezclarChuches(bolsaChuches &unaBolsa, bolsaChuches &otraBolsa)
    {
        for (std::vector<std::string>::iterator itChuches = otraBolsa.chuches.begin(); itChuches != otraBolsa.chuches.end(); ++itChuches)
        {
            unaBolsa.addChuche(*itChuches);
        }
    }

    int getCantidadChuches()
    {
        this->chuches.size();
    }

    void addChuche(std::string &chuche)
    {
        this->chuches.push_back(chuche);
    }

    std::string comerCuche(int sel)
    {
        std::string chuche = this->chuches[sel];
        std::vector<std::string>::iterator itChuches = this->chuches.begin();
        std::advance(itChuches, sel);
        this->chuches.erase(itChuches);

        return chuche;
    }

    std::string getAListOfChuches(char separator)
    {
        std::string strSeparatedBy = "";
        for (std::vector<std::string>::iterator itChuches = this->chuches.begin(); itChuches != this->chuches.end(); ++itChuches)
        {
            strSeparatedBy += *itChuches + separator;
        }

        return strSeparatedBy;
    }
};

int main()
{
    bolsaChuches *miBolsa = new bolsaChuches();
    std::string chuche1 = "Gominola";
    std::string chuche2 = "Cocacola";

    miBolsa->addChuche(chuche1);
    miBolsa->addChuche(chuche2);
    std::cout << miBolsa->getAListOfChuches(',') << std::endl;
}

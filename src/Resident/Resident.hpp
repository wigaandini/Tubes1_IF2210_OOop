#ifndef _RESIDENT_HPP_
#define _RESIDENT_HPP_

#include "../Player/Player.hpp"
#include "../Utils/Utils.hpp"
#include <functional>
#include <limits>
#include <string>
#include <limits>
using namespace std;
class Resident : public Player
{

public:
    Resident();
    Resident(string, int, int);
    ~Resident();
    virtual int calculateTax() = 0;
    virtual void harvest() = 0;
    virtual int getWealth() = 0;

protected:
    template <class T, class U>
    void harvest(T &source, map<string, U> &config, map<string, vector<string>> harvestResult, const string &name)
    {
        if (source.isEmpty())
        {
            cout << endl
                 << name << " anda kosong" << endl;
        }
        else if (!source.checkReadyToHarvest())
        {
            cout << endl
                 << name << " anda tidak ada yang siap dipanen" << endl;
        }
        else
        {
            source.displayStorage(true);
            cout << endl
                 << "Pilih " << (name == "Peternakan" ? "hewan" : "tanaman")
                 << " siap panen yang kamu miliki" << endl;
            map<string, int> plantReady = source.countItemsReadyToHarvest();
            int number = 1;
            vector<int> total;
            vector<string> kode;
            vector<int> sizeResult;

            for (const auto &entry : plantReady)
            {
                cout << "    " << number << ". " << config[entry.first].code << " (" << entry.second << " petak siap panen)" << endl;
                number++;
                kode.push_back(config[entry.first].code);
                total.push_back(entry.second);
                sizeResult.push_back(int(harvestResult[entry.first].size()));
            }

            int answer1, answer2;
            bool sukses1 = false;
            while (!sukses1)
            {
                cout << endl
                     << "Nomor " << (name == "Peternakan" ? "hewan" : "tanaman")
                     << " yang ingin dipanen (ketik -1 untuk keluar) : ";
                cin >> answer1;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Input harus berupa angka. Silahkan coba lagi." << endl;
                    continue;
                } 

                if (answer1 == -1)
                {
                    cout << "Tidak jadi panen!!" << endl;
                    return;
                }
                if (answer1 > 0 && answer1 < number)
                {
                    sukses1 = true;
                }
                else
                {
                    cout << "Masukan salah silahkah masukan kembali!!!" << endl;
                }
            }

            bool sukses2 = false;
            while (!sukses2)
            {
                cout << endl
                     << "Berapa petak yang ingin dipanen : ";
                cin >> answer2;

                if (answer2 <= total[answer1 - 1])
                {
                    if (answer2 * sizeResult[answer1 - 1] > this->inventory.countEmpty())
                    {
                        cout << endl
                             << "Jumlah penyimpanan tidak cukup!" << endl;
                        return;
                    }
                    else
                    {
                        sukses2 = true;
                    }
                }
                else
                {
                    cout << "Jumlah yang bisa dipanen hanya " << total[answer1 - 1] << "!!!" << endl;
                }
            }

            string slot;
            vector<string> petak;
            cout << "Pilih petak yang ingin dipanen: " << endl;
            for (int i = 0; i < answer2; i++)
            {
                bool sukses3 = false;
                while (!sukses3)
                {
                    try
                    {
                        cout << "Petak ke-" << i + 1 << " : ";
                        cin >> slot;
                        if (source.see(slot)->getCode() != kode[answer1 - 1])
                        {
                            cout << "Petak tidak sesuai. Silahkan input kembali!" << endl;
                        }
                        else
                        {
                            petak.push_back(slot);
                            sukses3 = true;
                        }
                    }
                    catch (const exception &e)
                    {
                        cout << e.what() << endl;
                    }
                }

                vector<shared_ptr<Product>> tempP = source.take(slot)->collect();
                unsigned int k = 0;
                while (k < tempP.size())
                {
                    this->inventory + tempP[k];
                    k++;
                }
            }
            cout << endl
                 << answer2 << " petak " << (name == "Peternakan" ? "hewan " : "tanaman ") << kode[answer1 - 1] << " pada petak ";
            for (int l = 0; l < answer2; l++)
            {
                if (l != answer2 - 1)
                {
                    cout << petak[l] << ", ";
                }
                else
                {
                    cout << petak[l];
                }
            }
            cout << " telah dipanen" << endl;
        }
    };

    template <class T, class X, class U>
    void placeTo(T &target, map<string, X> &config, function<bool()> checkInventory, const string &name)
    {
        if (this->inventory.isEmpty())
        {
            cout << endl
                 << "Inventory anda kosong!!" << endl;
        }
        else if (!checkInventory())
        {
            cout << endl
                 << "Inventory anda tidak ada tanaman!!" << endl;
        }
        else if (target.isFull())
        {
            cout << endl
                 << name << " anda penuh!!" << endl;
        }
        else
        {
            bool success = false;
            while (!success)
            {
                cout << "Pilih " << (name == "Peternakan" ? "hewan" : "tanaman")
                     << " dari penyimpanan" << endl;
                this->inventory.displayStorage(false);

                cout << endl
                     << "Slot (ketik q untuk keluar) : ";
                string slot;
                cin >> slot;

                if (slot == "q")
                {
                    cout << "Tidak jadi melakukan " << (name == "Peternakan" ? "ternak!!" : "tanam!!")
                         << endl;
                    return;
                }

                try
                {
                    if (config.find(this->inventory.see(slot)->getName()) != config.end())
                    {
                        string itemName = this->inventory.see(slot)->getName();
                        cout << endl
                             << "Kamu memilih " << Utils::toTitleCase(itemName) << "." << endl;
                        cout << endl
                             << "Pilih petak tanah yang akan " << (name == "Peternakan" ? "ditinggali" : "ditanami") << endl;
                        shared_ptr<Item> itemRef = this->inventory.take(slot);
                        shared_ptr<U> ref = dynamic_pointer_cast<U>(itemRef);

                        bool done = false;
                        while (!done)
                        {
                            try
                            {
                                target.displayStorage(false);

                                cout << endl
                                     << "Petak tanah (ketik q untuk kembali) : ";
                                string petak;
                                cin >> petak;

                                if (petak == "q")
                                {
                                    this->inventory.put(slot, itemRef);
                                    done = true;
                                    break;
                                }

                                if (!target.isEmpty(petak))
                                {
                                    cout << endl
                                         << "Petak sudah terisi." << endl
                                         << "Silahkan masukan petak yang kosong." << endl;
                                }
                                else
                                {
                                    target.put(petak, ref);

                                    if (name == "Ladang")
                                    {

                                        cout << endl
                                             << "Cangkul, cangkul, cangkul yang dalam~!" << endl
                                             << Utils::toTitleCase(itemName) << " berhasil ditanam!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Dengan hati-hati, kamu meletakkan seekor " << Utils::toTitleCase(itemName) << " di kandang." << endl;
                                        cout << Utils::toTitleCase(itemName) << " telah menjadi peliharaanmu sekarang!" << endl;
                                    }
                                    done = true;
                                }
                                success = true;
                            }
                            catch (const exception &e)
                            {
                                cout << endl
                                     << e.what() << endl
                                     << endl;
                            }
                        }
                    }
                    else
                    {
                        if (name == "Ladang")
                        {

                            cout << "Apa yang kamu lakukan?!! Kamu mencoba untuk menanam itu?!!" << endl;
                        }
                        else
                        {
                            cout << "Apa yang kamu lakukan?!! Benda yang kamu ambil bukanlah hewan?!!" << endl;
                        }
                        cout << "Silahkan masukan slot yang berisi " << (name == "Peternakan" ? "hewan." : "tanaman.")
                             << endl;
                    }
                }
                catch (const SlotEmptyException &e)
                {
                    cout << endl
                         << "Kamu mengambil harapan kosong dari penyimpanan." << endl
                         << "Silahkan masukan slot yang berisi " << (name == "Peternakan" ? "hewan." : "tanaman.")
                         << endl
                         << endl;
                }
                catch (const exception &e)
                {
                    cout << endl
                         << e.what() << endl
                         << endl;
                }
            }
        }
    };
};

#endif
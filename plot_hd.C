#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void plot_hd()
{
    const char *in_file_name = "mag.root";

    const int nz = 25;
    const int ny = 3;
    map<int, int> apa2iy;
    map<int, int> apa2iz;
    for (int apa=0; apa<150; ++apa) {
        if (apa%6>2) continue;
        int iz = apa / 6;
        int iy = apa % 6;
        apa2iy[apa] = iy;
        apa2iz[apa] = iz;
    }
    map<pair<int,int>, int> iyz2apa;
    for (int apa=0; apa<150; ++apa) {
        int iz = apa2iz[apa];
        int iy = apa2iy[apa];
        iyz2apa[{iy, iz}] = apa;
    }

    // selection to draw, [izmin, izmax) x [iymin, iymax)
    int izmin = 1;
    int izmax = 5;
    int iymin = 0;
    int iymax = 2;

    int niz = izmax - izmin;
    int niy = iymax - iymin;

    auto in_file = TFile::Open(in_file_name, "READ");

    TCanvas *c0 = new TCanvas("c0", "c0");
    c0->Divide(niz, niy);
    string branch_base = "hw_gauss";
    int n_filled = 0, n_total = 0;
    for (int iz = izmin; iz < izmax; ++iz)
    {
        for (int iy = iymin; iy < iymax; ++iy)
        {
            n_total++;
            if (iyz2apa.find({iy, iz}) == iyz2apa.end()) {
                continue;
            }
            int apa = iyz2apa[{iy, iz}];
            string hist_name = branch_base + to_string(apa);
            auto hist = (TH2F *)in_file->Get(hist_name.c_str());
            if (!hist)
            {
                // std::cerr << "Can not find " << hist_name.c_str() << std::endl;
                continue;
            }

            // hist for axis
            const auto ha_name = hist_name + "axis";
            auto ha = new TH2F(ha_name.c_str(), hist_name.c_str(),
                               hist->GetXaxis()->GetNbins(),
                               hist->GetXaxis()->GetXmin(),
                               hist->GetXaxis()->GetXmax(),
                               2000, 1500, 3500);
            ha->GetXaxis()->SetTitle("channel");
            ha->GetYaxis()->SetTitle("tick");
            ha->SetStats(0);
            ha->SetMaximum(40000);
            ha->SetMinimum(0);

            auto ipad = (niy - (iy - iymin)) * niz + (iz - izmax) + 1;
            c0->cd(ipad)->SetGrid();
            cout << ipad << endl;
            ha->Draw("colz");
            hist->Draw("colz same");
            n_filled++;
        }
    }
    std::cout << "n_filled/n_total: " << n_filled << "/" << n_total << std::endl;
}
#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void plot_hd()
{
    const char *in_file_name = "mag.root";

    // selection to draw, [izmin, izmax) x [iymin, iymax)
    int izmin = 0;
    int izmax = 7;
    int iymin = 0;
    int iymax = 3;


    const int nz = 25;
    const int ny = 3;
    map<int, int> apa2iy;
    map<int, int> apa2iz;
    for (int apa=0; apa<150; ++apa) {
        if (apa%6>2) continue;
        // if (apa%6<3) continue;
        int iz = apa / 6;
        int iy = apa % 3;
        apa2iy[apa] = iy;
        apa2iz[apa] = iz;
    }
    map<pair<int,int>, int> iyz2apa;
    for (int apa=0; apa<150; ++apa) {
        int iz = apa2iz[apa];
        int iy = apa2iy[apa];
        iyz2apa[{iy, iz}] = apa;
    }

    int niz = izmax - izmin;
    int niy = iymax - iymin;

    auto in_file = TFile::Open(in_file_name, "READ");

    TCanvas *c0 = new TCanvas("c0", "c0");
    c0->Divide(niz, niy);
    string branch_base = "hw_gauss";
    int n_filled = 0, n_total = 0;
    for (int iz = izmin; iz < izmax; ++iz)
    {
        for (int iy = iymin; iy < iymax; ++iy)
        {
            n_total++;
            if (iyz2apa.find({iy, iz}) == iyz2apa.end()) {
                continue;
            }
            int apa = iyz2apa[{iy, iz}];
            string hist_name = branch_base + to_string(apa);
            auto hist = (TH2F *)in_file->Get(hist_name.c_str());
            if (!hist)
            {
                // std::cerr << "Can not find " << hist_name.c_str() << std::endl;
                continue;
            }

            // hist for axis
            const auto ha_name = hist_name + "axis";
            auto ha = new TH2F(ha_name.c_str(), hist_name.c_str(),
                               hist->GetXaxis()->GetNbins(),
                               hist->GetXaxis()->GetXmin(),
                               hist->GetXaxis()->GetXmax(),
                               3000, 500, 3500);
            ha->GetXaxis()->SetTitle("channel");
            ha->GetYaxis()->SetTitle("tick");
            ha->SetStats(0);
            ha->SetMaximum(40000);
            ha->SetMinimum(0);

            auto ipad = (niy - (iy - iymin)) * niz + (iz - izmax) + 1;
            c0->cd(ipad)->SetGrid();
            cout << ipad << endl;
            ha->Draw("colz");
            hist->Draw("colz same");
            n_filled++;
        }
    }
    std::cout << "n_filled/n_total: " << n_filled << "/" << n_total << std::endl;
}


#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void plot_crp()
{
    const char* in_file_name = "mag-sim-sp.root";

    const int nz = 40;
    const int ny = 4;

    // all
    int izmin = 0;
    int izmax = 5;
    int iymin = 0;
    int iymax = 2;

    int niz = izmax - izmin;
    int niy = iymax - iymin;

    auto in_file = TFile::Open(in_file_name, "READ");

    TCanvas* c0 = new TCanvas("c0", "c0");
    c0->Divide(niz, niy);
    string branch_base = "hw_gauss";
    int n_filled = 0, n_total = 0;
    for (int iz = izmin; iz < izmax; ++iz) {
        for (int iy = iymin; iy < iymax; ++iy) {
            n_total++;
            string hist_name = branch_base + to_string(iz * ny + iy);
            auto hist = (TH2F*) in_file->Get(hist_name.c_str());
            if(!hist) {
                // std::cerr << "Can not find " << hist_name.c_str() << std::endl;
                continue;
            }
            hist->SetStats(0);

            const auto ha_name = hist_name + "axis";
            auto ha = new TH2F(ha_name.c_str(), ha_name.c_str(), hist->GetXaxis()->GetNbins(), hist->GetXaxis()->GetXmin(), hist->GetXaxis()->GetXmax(), 2000, 1500, 3500);

            // orig
            // u, v
            // hist->SetMaximum(1940);
            // hist->SetMinimum(1740);
            // w
            // hist->SetMaximum(510);
            // hist->SetMinimum(310);

            // gauss
            hist->SetMaximum(40000);
            hist->SetMinimum(0);

            // hist->GetXaxis()->SetRangeUser(7650,7780);
            // hist->GetYaxis()->SetRangeUser(6500,8500);

            auto ipad = (niy - (iy - iymin)) * niz + (iz - izmax) + 1;
            cout << ipad << endl;
            n_filled++;
            c0->cd(ipad)->SetGrid();
            hist->GetXaxis()->SetTitle("channel");
            hist->GetYaxis()->SetTitle("tick");
            hist->Draw("colz");
        }
    }
    std::cout << "n_filled/n_total: " << n_filled << "/" << n_total << std::endl;
}

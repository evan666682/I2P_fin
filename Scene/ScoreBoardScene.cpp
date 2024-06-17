#include <allegro5/allegro_audio.h>
#include <functional>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>//
#include <sstream>//



#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#include "UI/Component/Slider.hpp"
#include "ScoreBoardScene.hpp"

//to print scoretxt 
#include <vector>//
std::vector<std::string> scoreboardData;
int page=0;
const int itemsPerPage=6;
int ScoreBoardScene::isloading=0;

void ScoreBoardScene::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton* btn;

    AddNewObject(new Engine::Label("Score Board", "Rainbow-Party.ttf", 90, halfW, halfH / 5, 10, 255, 255, 255, 0.5, 0.5));
    
    // Read txt and store data
    if(!isloading){
        std::string fname = "../Resource/scoreboard.txt";
        std::ifstream fin(fname);
        std::string pplname, pplscore, tmstamp;
        int rank = 1;
        std::stringstream formattedLine;
        scoreboardData.clear();
        while (fin >> pplname >> pplscore >> tmstamp) {
            formattedLine.str("");
            formattedLine.clear(); 
            formattedLine << std::right << std::setw(5) << rank 
                            <<std::right << std::setw(15) << pplname 
                            <<std::right << std::setw(8) << pplscore 
                            <<std::right << std::setw(30) << tmstamp ;
            scoreboardData.push_back(formattedLine.str());
            rank++;
        }
        fin.close();
        isloading=1;
    }
    
    //print
    std::stringstream topicformatted;
    topicformatted.str("");
    topicformatted.clear(); 
    topicformatted << std::right << std::setw(5) << "order" 
                    << std::right << std::setw(15) << "Player" 
                    << std::right << std::setw(8) << "Score" 
                    << std::right << std::setw(30) << "Record Time" ;
    AddNewObject(new Engine::Label(topicformatted.str(), "Rainbow-Party.ttf", 40, halfW, halfH / 5 + 100, 10, 255, 255, 255, 0.5, 0.5));
    int first_data_height = halfH / 5 + 150;
    int space_for_datas = 40;
    int startIdx = page * itemsPerPage;
    int endIdx = std::min(startIdx + itemsPerPage, (int)scoreboardData.size());
    for (int i = startIdx; i < endIdx; i++) {
        AddNewObject(new Engine::Label(scoreboardData[i], "Rainbow-Party.ttf", 40, halfW, first_data_height, 10, 255, 255, 255, 0.5, 0.5));
        first_data_height += space_for_datas;
    }

    //Next 按鈕
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW *3/2, halfH * 7 / 4 - 50, 200, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::NextPage, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next", "Spooky-Light.ttf", 48, halfW *3/2+100, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));

    //Prev 按鈕
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW *1/2-200, halfH * 7 / 4 - 50, 200, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::PrevPage, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Prev", "Spooky-Light.ttf", 48, halfW *1/2-100, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::BackOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "Spooky-Light.ttf", 48, halfW, halfH * 7 / 4, 0, 0, 0, 255, 0.5, 0.5));

    
    // (Not safe if release resource while playing, however we only free while change scene, so it's fine.)
	bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
}



void ScoreBoardScene::NextPage() {
    if ((page + 1) * itemsPerPage < scoreboardData.size()){
        page++;
        Engine::GameEngine::GetInstance().ChangeScene("scoreboard-scene");
    } 
    
}

void ScoreBoardScene::PrevPage() {
    if (page>0){
        page--;
        Engine::GameEngine::GetInstance().ChangeScene("scoreboard-scene");
    } 
    
}

////////////////////////////////////////////////



void ScoreBoardScene::Terminate() {
	AudioHelper::StopSample(bgmInstance);
	bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
	IScene::Terminate();
}
void ScoreBoardScene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}


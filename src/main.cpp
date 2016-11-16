#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <boost/format.hpp>
#include "mkdir.h"
#include "characterrecognizer.h"

int main() try{
	enum MOJI{
		A,I,U,E,O,KA,KI,KU,KE,KO,SA,SI,SU,SE,SO,TA,TI,TU,TE,TO,NA,NI,NU,NE,NO,HA,HI,HU,HE,HO,MA,MI,MU,ME,MO,YA,YU,YO,RA,RI,RU,RE,RO,WA,WO,N
	};

	typedef struct{
		std::vector<CharacterRecognizer::feature> features;
		CharacterRecognizer::feature feature_average;
	}moji_type;

	std::array<moji_type, 46> mojis;
	CharacterRecognizer::FeatureCalculator featureCalculator;

	std::cout << "Start!" << std::endl;

	// 教師データの読み込み
	for(std::size_t i=0;i<46;++i){
		std::string file_path = (boost::format("data/課題データ/c%02d.txt") % (i+1)).str();
		mojis.at(i).features = featureCalculator.readNewFeatures(file_path, 180);
	}

	// 平均特徴量の生成
	for(std::size_t i=0;i<46;++i){
		mojis.at(i).feature_average = featureCalculator.createFeatureAverage(mojis.at(i).features);
	}

	// 平均特徴量をファイルに出力
	for(std::size_t i=0;i<46;++i){
		std::createDir("./data/課題データ平均");
		std::string file_name = (boost::format("data/課題データ平均/mean%02d.txt") % (i+1)).str();
		featureCalculator.writeFeature(mojis.at(i).feature_average, file_name);
	}

	std::cout << "Finish!" << std::endl;

	return 0;
}catch(std::string error_message){
	std::cout<<"エラーが発生しました。エラーメッセージ："<<error_message<<std::endl;
}

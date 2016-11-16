#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <cstdio>
#include "feature.h"
#include "featurecalculator.h"

std::vector<CharacterRecognizer::feature> CharacterRecognizer::FeatureCalculator::readNewFeatures(std::string input_file_name, std::size_t features_size){
	FILE *reader;
	char buf[256];

	std::vector<feature> features;

	if((reader = fopen(input_file_name.c_str(), "r")) == NULL){
		throw std::string("Missing file:"+input_file_name+" stop.");
	}
	
	// 汚いがifstreamは激遅だったので妥協
	std::size_t features_cnt = 0;
	while(1){
		if (features_cnt == features_size) break;
		feature new_feature;
		bool is_exit = false;
		for (std::size_t i = 0; i < 196; ++i){
			if (fgets(buf, 256, reader) == NULL){
				is_exit = true;
				break;
			}
			new_feature.at(i) = atof(buf);
		}
		if (is_exit) break;
		features.emplace_back(new_feature);
		++features_cnt;
	}
	fclose(reader);

	return std::move(features);
}

CharacterRecognizer::feature CharacterRecognizer::FeatureCalculator::createFeatureAverage(std::vector<feature> features){
	// calculate features sum
	feature sum_feature;
	for (std::size_t i = 0; i < 196; ++i){
		sum_feature.at(i) = 0;
	}
	for (std::size_t features_cnt = 0; features_cnt < features.size(); ++features_cnt){
		for (std::size_t i = 0; i < 196; ++i){
			sum_feature.at(i) += features.at(features_cnt).at(i);
		}
	}
	// insert average
	for (std::size_t i = 0; i < 196; ++i){
		sum_feature.at(i) /= 196;
	}

	return std::move(sum_feature);
}

void CharacterRecognizer::FeatureCalculator::writeFeature(feature feature, std::string output_file_name){
	std::ofstream writer(output_file_name, std::ios::out);
	for (std::size_t i = 0; i < 196; ++i){
		writer << feature.at(i) << std::endl;
	}
	writer.close();
}

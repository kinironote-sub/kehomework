#pragma once
#include <array>
#include <vector>
#include <memory>
#include "feature.h"

namespace CharacterRecognizer{
	class FeatureCalculator
	{
	public:
		// 特徴量ファイルから特徴量を取得
		std::vector<feature> readNewFeatures(std::string input_file_name, std::size_t features_size = 1);

		// features.at(moji)に存在する特徴量データすべての平均を計算してfeature_averageに挿入
		feature createFeatureAverage(std::vector<feature> features);

		// feature_averageをファイルに出力
		void writeFeature(feature feature, std::string output_file_name);
	};
}

#pragma once

namespace serenity {

	namespace helper_ostream {
		static std::string global_ostream {"std::cout"};

		enum class InterfaceType : unsigned int { cout=0, clog=1, cerr=2 };

		const auto InterfaceTypeToStr(InterfaceType ostream)
		{
			std::map<InterfaceType, std::string> ostreamMap = {

			  {InterfaceType::cout, "std::cout"},
			  {InterfaceType::cerr, "std::cerr"},
			  {InterfaceType::clog, "std::clog"}

			};
			std::string resultString = "UNKNOWN";
			auto iterator            = ostreamMap.find(ostream);
			if(iterator != ostreamMap.end( )) {
				resultString = iterator->second;
			}
			return resultString;
		}

		const auto SetOstreamType(InterfaceType ostream)
		{
			global_ostream = InterfaceTypeToStr(ostream);
		}

		const auto GetOstreamType( )
		{
			if(global_ostream == "std::cout") {
				std::ostream& os = std::cout;
				return &os;
			} else if(global_ostream == "std::cerr") {
				std::ostream& os = std::cerr;
				return &os;
			} else {
				std::ostream& os = std::cout;
				return &os;
			}
		}

	} // namespace helper_ostream


} // namespace serenity
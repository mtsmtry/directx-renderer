#include "Core\Public\Script\Json.h"
#include "Core\Public\Script\Lexer.h"
#include "dropbox\json11.hpp"
#include "rapidjson\document.h"
#include <iostream>
#include <locale> 
#include <codecvt> 
#include <cstdio>
#include <sstream>
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

void JsonBenchmark()
{
	auto Text = "{\"s\":\"ok\",\"t\":[1519689600,1519693200,1519696800,1519700400,1519704000,1519707600,1519711200,1519714800,1519718400,1519722000,1519725600,1519729200,1519732800,1519736400,1519740000,1519743600,1519747200,1519750800,1519754400,1519758000,1519761600,1519765200,1519768800,1519772400,1519776000,1519779600,1519783200,1519786800,1519790400,1519794000,1519797600,1519801200,1519804800,1519808400,1519812000,1519815600,1519819200,1519822800,1519826400,1519830000,1519833600,1519837200,1519840800,1519844400,1519848000,1519851600,1519855200,1519858800,1519862400,1519866000,1519869600,1519873200,1519876800,1519880400,1519884000,1519887600,1519891200,1519894800,1519898400,1519902000,1519905600,1519909200,1519912800,1519916400,1519920000,1519923600,1519927200,1519930800,1519934400,1519938000,1519941600,1519945200,1519948800,1519952400,1519956000,1519959600,1519963200,1519966800,1519970400,1519974000,1519977600,1519981200,1519984800,1519988400,1519992000,1519995600,1519999200,1520002800,1520006400,1520010000,1520013600,1520017200,1520020800,1520024400,1520028000,1520031600,1520035200,1520038800,1520042400,1520046000,1520049600,1520053200,1520056800,1520060400,1520064000,1520067600,1520071200,1520074800,1520078400,1520082000,1520085600,1520089200,1520092800,1520096400,1520100000,1520103600,1520107200,1520110800,1520114400,1520118000,1520121600,1520125200,1520128800,1520132400,1520136000,1520139600,1520143200,1520146800,1520150400,1520154000,1520157600,1520161200,1520164800,1520168400,1520172000,1520175600,1520179200,1520182800,1520186400,1520190000,1520193600,1520197200,1520200800,1520204400,1520208000,1520211600,1520215200,1520218800,1520222400,1520226000,1520229600,1520233200,1520236800,1520240400,1520244000,1520247600,1520251200],\"c\":[10362,10197.5,10163.71,10275.38,10291.55,10311.04,10305.34,10617.81,10691.69,10733.13,10649.36,10698.48,10673.02,10847.29,10671.26,10574.55,10623.91,10573.96,10615.49,10673.21,10661.96,10751.24,10714.43,10566.44,10644.75,10688.94,10677.65,10906.77,10902.36,10940.24,10805.25,10747.79,10500.84,10594.02,10578.73,10562.45,10408.79,10469.95,10510.44,10500.28,10400,10441.08,10478.98,10538.13,10649.21,10534.45,10419.5,10311.08,10387.99,10407.38,10325.39,10349.91,10433.12,10397.06,10387.59,10523.04,10623.57,10591.59,10729,10652.39,10626.78,10761,10772.45,10704.16,10739.83,10836.69,10926.65,10899.24,11037.5,10923.48,10972.36,10899.53,11012.2,11125.65,11033.4,11090,10994.37,10986.75,11087.69,11075.02,11093.46,10885.28,10911,10908.42,11017.48,10965.01,10787,10857,10851.83,10896.54,10923.78,10909.99,11049.94,11026.47,11091.27,11015,11068.42,11200.17,11297.21,11304.91,11354.49,11309.92,11323.28,11287.58,11338.18,11305.42,11311.66,11276.86,11391.18,11439.08,11401.51,11454.98,11447.98,11491.45,11462,11456,11281.96,11301.51,11386.32,11438.75,11353.84,11381.15,11318.44,11167.5,11196,11200.82,11121.01,11142.55,11206.74,11228.4,11145.51,11141.06,11207,11187.35,11116.52,11125.75,11134.35,11118.5,11338.01,11343.54,11443.5,11398,11371.09,11466.59,11452.18,11448.27,11503.99,11555.69,11508.86,11509.27,11522.97,11508.56,11440.38,11448,11468.16,11490,11533.5],\"o\":[10315,10362,10197.5,10163.71,10275.38,10291.55,10311.04,10305.34,10617.81,10691.69,10733.13,10649.36,10698.48,10673.02,10847.29,10671.26,10574.55,10623.91,10573.96,10615.49,10673.21,10661.96,10751.24,10714.43,10566.44,10644.75,10688.94,10677.65,10906.77,10902.36,10940.24,10805.25,10747.79,10500.84,10594.02,10578.73,10562.45,10408.79,10469.95,10510.44,10500.28,10400,10441.08,10478.98,10538.13,10649.21,10534.45,10419.5,10311.08,10387.99,10407.38,10325.39,10349.91,10433.12,10397.06,10387.59,10523.04,10623.57,10591.59,10729,10652.39,10626.78,10761,10772.45,10704.16,10739.83,10836.69,10926.65,10899.24,11037.5,10923.48,10972.36,10899.53,11012.2,11125.65,11033.4,11090,10994.37,10986.75,11087.69,11075.02,11093.46,10885.28,10911,10908.42,11017.48,10965.01,10787,10857,10851.83,10896.54,10923.78,10909.99,11049.94,11026.47,11091.27,11015,11068.42,11200.17,11297.21,11304.91,11354.49,11309.92,11323.28,11287.58,11338.18,11305.42,11311.66,11276.86,11391.18,11439.08,11401.51,11454.98,11447.98,11491.45,11462,11456,11281.96,11301.51,11386.32,11438.75,11353.84,11381.15,11318.44,11167.5,11196,11200.82,11121.01,11142.55,11206.74,11228.4,11145.51,11141.06,11207,11187.35,11116.52,11125.75,11134.35,11118.5,11338.01,11343.54,11443.5,11398,11371.09,11466.59,11452.18,11448.27,11503.99,11555.69,11508.86,11509.27,11522.97,11508.56,11440.38,11448,11468.16,11490],\"h\":[10399.72,10373.18,10237.51,10316.08,10338,10335.18,10356.08,10625.65,10736.65,10769.11,10729.98,10739.27,10730.19,10847.29,10847.28,10673.27,10659.24,10625.87,10632.79,10723.71,10710.98,10770,10788.45,10731.73,10663.81,10695.95,10767.22,10953.29,10973.38,10951.07,11040.56,10809.18,10798.92,10622.2,10633,10634.02,10604.8,10500.75,10554.22,10565.53,10522.33,10486.01,10543.72,10538.13,10673.5,10686.49,10561.67,10455.87,10397.96,10407.38,10438.32,10381.82,10448.66,10428.51,10400.5,10537.97,10636.76,10631.66,10729,10732.16,10706.47,10797.33,10794.71,10764.77,10763.97,10856.99,10935.12,10942.49,11073.53,11058.05,10972.99,10982.34,11058.39,11157.5,11138.99,11113.87,11124.21,11026.37,11099.5,11121.01,11131,11098.05,10938.88,10935.14,11017.48,11037.79,10976,10859.2,10864.07,10896.54,10930.66,10921.75,11066.18,11058.77,11093.4,11094.29,11084.99,11215,11341,11325.71,11367.71,11359.76,11376.63,11362.09,11338.18,11342.49,11339.04,11338.71,11410.96,11475.14,11462.25,11472.5,11463.49,11496.88,11491.44,11479.49,11464.93,11339.2,11391.43,11453.41,11443.62,11400,11381.16,11310.31,11209.51,11212.58,11203,11142.55,11206.88,11252.66,11229.42,11175.19,11219.12,11231,11191.01,11126.11,11158.53,11142.89,11348.5,11382.49,11443.5,11462.93,11400.35,11499,11482.15,11459.05,11507.65,11578.65,11598.12,11528.25,11546.99,11563.07,11524.29,11470,11476.88,11509.92,11555.18],\"l\":[10297.17,10151.58,10149.83,10170.57,10274.04,10222.58,10241.51,10306.67,10618.8,10659.33,10615,10640.84,10651.21,10674.46,10657.38,10479.35,10567.55,10546.37,10564.95,10624.11,10597.7,10646.33,10696.01,10566.44,10552.31,10625.58,10674.47,10673.07,10889.25,10893.54,10794.01,10669.01,10500.84,10478.41,10503.33,10527.65,10388.5,10384.68,10448.62,10473.3,10400,10402.75,10446.5,10475.05,10560.4,10534.45,10419.5,10277.51,10224.33,10317.56,10290.43,10304.65,10360.49,10367.07,10332.27,10397.25,10538.5,10568.42,10595.82,10652.39,10618.92,10634.84,10738.9,10663.99,10693.84,10704.1,10816.51,10851.69,10873.38,10879,10809.28,10885.88,10909.95,10977.69,11030.17,11043.05,10953.13,10912.43,10995.94,11021.22,11044.2,10867.75,10826.41,10837.82,10909.94,10954.66,10787,10808.92,10794,10837.99,10865,10862.92,10880.35,10987.73,11022.75,10947.24,11029.95,11075.3,11180.84,11237.18,11300.51,11280.5,11304.51,11274.73,11231.68,11273.01,11298.21,11258.48,11284.72,11383.22,11386.44,11396.49,11434.79,11416.63,11445.05,11447.44,11239.5,11267.03,11287.28,11371.89,11349.68,11356.49,11270.81,11117,11113.34,11151.61,11112.53,11062.79,11122.91,11177.51,11110.96,11090.5,11142.56,11155,11114.98,11083.77,11110.09,11118.5,11113.47,11334.42,11360.5,11382.66,11331.82,11376.53,11396.54,11403.23,11442.72,11458.14,11508.86,11458.55,11504.76,11498.62,11422.5,11432.27,11416.13,11454.97,11495.91],\"v\":[0,0,0,0,0]}";

	const int Count = 100;

	// rapidjson by Milo Yip
	clock_t Start = clock();
	for (int i = 0; i < Count; i++)
	{
		rapidjson::Document Document;
		if (Document.Parse<0>(Text).HasParseError())
		{
			MessageBoxA(nullptr, "Rapidjson Error", "", MB_OK);
		}
	}
	double RapidjsonTime = (double)(clock() - Start) / CLOCKS_PER_SEC;

	// json11 by Dropbox
	string Error;
	for (int i = 0; i < Count; i++)
	{
		auto DropboxJson = json11::Json::parse(Text, Error);
		if (!Error.empty())
		{
			MessageBoxA(nullptr, "Dropbox Json Error", "", MB_OK);
		}
	}
	double DropboxTime = (double)(clock() - Start) / CLOCKS_PER_SEC;

	// Lexical Analyze by Me
	Start = clock();
	for (int i = 0; i < Count; i++)
	{
		auto Lexer = SLexer::Default();
		Lexer.Analyze(Text);
	}
	double MyLexicalTime = (double)(clock() - Start) / CLOCKS_PER_SEC;

	// Json by Me
	Start = clock();
	for (int i = 0; i < Count; i++)
	{
		SJson MyJson(Text);
		if (MyJson.IsError)
		{
			MessageBoxA(nullptr, "My Json Error", "", MB_OK);
		}
	}
	double MyTime = (double)(clock() - Start) / CLOCKS_PER_SEC;

	ostringstream Stream;
	Stream << "Rapidjson:" << RapidjsonTime
		<< "\nDropboxTime:" << DropboxTime
		<< "\nMyTime:" << MyTime
		<< "\nMyLexicalTime:" << MyLexicalTime
		<< "\nMyParsingTime:" << MyTime - MyLexicalTime
		<< "\nRapidjson x" << MyTime / RapidjsonTime
		<< "\nDropbox x" << MyTime / DropboxTime;
	string ResultString = Stream.str();
	MessageBoxA(nullptr, &ResultString[0], "", MB_OK);

	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> Conveter;
	FFileManager::WriteTextFile(L"JsonBenchmark.txt", Conveter.from_bytes(ResultString));
}
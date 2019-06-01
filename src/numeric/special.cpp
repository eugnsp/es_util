#include <es_util/numeric/const.hpp>
#include <es_util/numeric/special.hpp>

#include <cmath>

namespace es_util
{
/** References:

[Fuk15a] T.Fukushima
Precise and fast computation of Fermi-Dirac integral of integer and half integer order by piecewise
minimax rational approximation App.Math.Comp. 259, 708 (2015) 10.1016/j.amc.2015.03.009

[HS96] H.H.H.Homeier, E.O.Steinborn
Some properties of the coupling coefficients of real spherical harmonics and their relation to Gaunt
coefficients J.Mol.Struct. 368, 31 (1996) 10.1016/S0166-1280(96)90531-X

*/

//////////////////////////////////////////////////////////////////////////

// Computes ln(1 + exp(x))
double ln_one_p_exp(double x)
{
	if (x < 0)
		return std::log1p(std::exp(x));
	else
		return x + std::log1p(std::exp(-x));
}

//////////////////////////////////////////////////////////////////////////
/** Fermi-Dirac statistics */

// Returns the Fermi function, F(x) = 1 / (1 + exp(x))
double fermi(double x)
{
	if (x < 0)
		return 1 / (1 + std::exp(x));
	else
	{
		const double exp = std::exp(-x);
		return exp / (1 + exp);
	}
}

// Returns the Fermi-Dirac integral of order -1, F(x) = 1 / (1 + exp(-x))
double fd_int_minus_one(double x)
{
	return fermi(-x);
}

// Returns the Fermi-Dirac integral of order 0, F(x) = ln(1 + exp(x))
double fd_int_zero(double x)
{
	return ln_one_p_exp(x);
}

// Returns the Fermi-Dirac integral of order -3/2 [Fuk15a]
double fd_int_three_halves(double x)
{
	double fd;

	if (x < -2)
	{
		double ex = std::exp(x);
		double t = ex * 7.38905609893065023;
		fd = ex * (-3.54490770181103205 +
				   ex *
					   (82737.595643818605 +
						t * (18481.5553495836940 +
							 t * (1272.73919064487495 +
								  t * (26.3420403338352574 - t * 0.00110648970639283347)))) /
					   (16503.7625405383183 +
						t * (6422.0552658801394 +
							 t * (890.85389683932154 + t * (51.251447078851450 + t)))));
	}
	else if (x < 0)
	{
		double s = -.5 * x;
		double t = 1 - s;
		fd = -(946.638483706348559 +
			   t * (76.3328330396778450 +
					t * (62.7809183134124193 +
						 t * (83.8442376534073219 +
							  t * (23.2285755924515097 +
								   t * (3.21516808559640925 +
										t * (1.58754232369392539 +
											 t * (0.687397326417193593 +
												  t * .111510355441975495)))))))) /
			 (889.4123665319664 +
			  s * (126.7054690302768 +
				   s * (881.4713137175090 +
						s * (108.2557767973694 +
							 s * (289.38131234794585 +
								  s * (27.75902071820822 + s * (34.252606975067480 +
																s * (1.9592981990370705 + s))))))));
	}
	else if (x < 2)
	{
		double t = 0.5 * x;
		fd = -(754.61690882095729 +
			   t * (565.56180911009650 +
					t * (494.901267018948095 +
						 t * (267.922900418996927 +
							  t * (110.418683240337860 +
								   t * (39.4050164908951420 +
										t * (10.8654460206463482 +
											 t * (2.11194887477009033 +
												  t * .246843599687496060)))))))) /
			 (560.03894899770103 +
			  t * (70.007586553114572 +
				   t * (582.42052644718871 +
						t * (56.181678606544951 +
							 t * (205.248662395572799 +
								  t * (12.5169006932790528 +
									   t * (27.2916998671096202 +
											t * (0.53299717876883183 + t))))))));
	}
	else if (x < 5)
	{
		double t = 0.3333333333333333333 * (x - 2);
		fd = -(526.022770226139287 +
			   t * (631.116211478274904 +
					t * (516.367876532501329 +
						 t * (267.894697896892166 +
							  t * (91.3331816844847913 +
								   t * (17.5723541971644845 +
										t * (1.46434478819185576 +
											 t * (1.29615441010250662 +
												  t * .223495452221465265)))))))) /
			 (354.867400305615304 +
			  t * (560.931137013002977 +
				   t * (666.070260050472570 +
						t * (363.745894096653220 +
							 t * (172.272943258816724 +
								  t * (23.7751062504377332 +
									   t * (12.5916012142616255 +
											t * (-.888604976123420661 + t))))))));
	}
	else if (x < 10)
	{
		double t = 0.2 * x - 1;
		fd =
			-(18.0110784494455205 +
			  t * (36.1225408181257913 +
				   t * (38.4464752521373310 +
						t * (24.1477896166966673 +
							 t * (9.27772356782901602 +
								  t * (2.49074754470533706 + t * (0.163824586249464178 -
																  t * .00329391807590771789))))))) /
			(18.8976860386360201 +
			 t * (49.3696375710309920 +
				  t * (60.9273314194720251 +
					   t * (43.6334649971575003 +
							t * (20.6568810936423065 + t * (6.11094689399482273 + t))))));
	}
	else if (x < 20)
	{
		double t = 0.1 * x - 1;
		fd = -(4.10698092142661427 +
			   t * (17.1412152818912658 +
					t * (32.6347877674122945 +
						 t * (36.6653101837618939 +
							  t * (25.9424894559624544 +
								   t * (11.2179995003884922 +
										t * (2.30099511642112478 +
											 t * (0.0928307248942099967 -
												  t * .00146397877054988411)))))))) /
			 (6.40341731836622598 +
			  t * (30.1333068545276116 +
				   t * (64.0494725642004179 +
						t * (80.5635003792282196 +
							 t * (64.9297873014508805 +
								  t * (33.3013900893183129 + t * (9.61549304470339929 + t)))))));
	}
	else if (x < 40)
	{
		double t = 0.05 * x - 1;
		fd = -(95.2141371910496454 +
			   t * (420.050572604265456 +
					t * (797.778374374075796 +
						 t * (750.378359146985564 +
							  t * (324.818150247463736 +
								   t * (50.3115388695905757 +
										t * (0.372431961605507103 +
											 t * (-.103162211894757911 +
												  t * .00191752611445211151)))))))) /
			 (212.232981736099697 +
			  t * (1043.79079070035083 +
				   t * (2224.50099218470684 +
						t * (2464.84669868672670 +
							 t * (1392.55318009810070 +
								  t * (346.597189642259199 + t * (22.7314613168652593 - t)))))));
	}
	else
	{
		double w = 1 / (x * x);
		double s = 1 - 1600 * w;
		fd =
			-2 / std::sqrt(x) *
			(1 +
			 w *
				 (12264.3569103180524 +
				  s * (3204.34872454052352 + s * (140.119604748253961 + s * .523918919699235590))) /
				 (9877.87829948067200 + s * (2644.71979353906092 + s * (128.863768007644572 + s))));
	}

	return fd / (-2 * math::sqrt_pi);
}

// Returns the Fermi-Dirac integral of order -1/2 [Fuk15a]
double fd_int_minus_half(double x)
{
	double fd;

	if (x < -2)
	{
		double ex = std::exp(x);
		double t = ex * 7.38905609893065023;
		fd = ex * (1.77245385090551603 -
				   ex *
					   (40641.4537510284430 +
						t * (9395.7080940846442 +
							 t * (649.96168315267301 +
								  t * (12.7972295804758967 + t * .00153864350767585460)))) /
					   (32427.1884765292940 +
						t * (11079.9205661274782 +
							 t * (1322.96627001478859 + t * (63.738361029333467 + t)))));
	}
	else if (x < 0)
	{
		double s = -.5 * x;
		double t = 1 - s;
		fd = (272.770092131932696 +
			  t * (30.8845653844682850 +
				   t * (-6.43537632380366113 +
						t * (14.8747473098217879 +
							 t * (4.86928862842142635 +
								  t * (-1.53265834550673654 +
									   t * (-1.02698898315597491 +
											t * (-.177686820928605932 -
												 t * .00377141325509246441)))))))) /
			 (293.075378187667857 +
			  s * (305.818162686270816 +
				   s * (299.962395449297620 +
						s * (207.640834087494249 +
							 s * (92.0384803181851755 +
								  s * (37.0164914112791209 + s * (7.88500950271420583 + s)))))));
	}
	else if (x < 2)
	{
		double t = .5 * x;
		fd = (3531.50360568243046 +
			  t * (6077.5339658420037 +
				   t * (6199.7700433981326 +
						t * (4412.78701919567594 +
							 t * (2252.27343092810898 +
								  t * (811.84098649224085 +
									   t * (191.836401053637121 + t * 23.2881838959183802))))))) /
			 (3293.83702584796268 +
			  t * (1528.97474029789098 +
				   t * (2568.48562814986046 +
						t * (925.64264653555825 +
							 t * (574.23248354035988 +
								  t * (132.803859320667262 + t * (29.8447166552102115 + t)))))));
	}
	else if (x < 5)
	{
		double t = .3333333333333333333 * (x - 2);
		fd = (4060.70753404118265 +
			  t * (10812.7291333052766 +
				   t * (13897.5649482242583 +
						t * (10628.4749852740029 +
							 t * (5107.70670190679021 +
								  t * (1540.84330126003381 +
									   t * (284.452720112970331 + t * 29.5214417358484151))))))) /
			 (1564.58195612633534 +
			  t * (2825.75172277850406 +
				   t * (3189.16066169981562 +
						t * (1955.03979069032571 +
							 t * (828.000333691814748 +
								  t * (181.498111089518376 + t * (32.0352857794803750 + t)))))));
	}
	else if (x < 10)
	{
		double t = .2 * x - 1;
		fd = (1198.41719029557508 +
			  t * (3263.51454554908654 +
				   t * (3874.97588471376487 +
						t * (2623.13060317199813 +
							 t * (1100.41355637121217 +
								  t * (267.469532490503605 +
									   t * (25.4207671812718340 + t * .389887754234555773))))))) /
			 (273.407957792556998 +
			  t * (595.918318952058643 +
				   t * (605.202452261660849 +
						t * (343.183302735619981 +
							 t * (122.187622015695729 + t * (20.9016359079855933 + t))))));
	}
	else if (x < 20)
	{
		double t = .1 * x - 1;
		fd = (9446.00169435237637 +
			  t * (36843.4448474028632 +
				   t * (63710.1115419926191 +
						t * (62985.2197361074768 +
							 t * (37634.5231395700921 +
								  t * (12810.9898627807754 +
									   t * (1981.56896138920963 + t * 81.4930171897667580))))))) /
			 (1500.04697810133666 +
			  t * (5086.91381052794059 +
				   t * (7730.01593747621895 +
						t * (6640.83376239360596 +
							 t * (3338.99590300826393 +
								  t * (860.499043886802984 + t * (78.8565824186926692 + t)))))));
	}
	else if (x < 40)
	{
		double t = .05 * x - 1;
		fd = (22977.9657855367223 +
			  t * (123416.616813887781 +
				   t * (261153.765172355107 +
						t * (274618.894514095795 +
							 t * (149710.718389924860 +
								  t * (40129.3371700184546 +
									   t * (4470.46495881415076 + t * 132.684346831002976))))))) /
			 (2571.68842525335676 +
			  t * (12521.4982290775358 +
				   t * (23268.1574325055341 +
						t * (20477.2320119758141 +
							 t * (8726.52577962268114 +
								  t * (1647.42896896769909 + t * (106.475275142076623 + t)))))));
	}
	else
	{
		double w = 1 / (x * x);
		double t = 1600 * w;
		fd = std::sqrt(x) * 2 *
			 (1 -
			  w * (.411233516712009968 +
				   t * (.00110980410034088951 +
						t * (.0000113689298990173683 +
							 t * (2.56931790679436797e-7 +
								  t * (9.97897786755446178e-9 + t * 8.67667698791108582e-10))))));
	}

	return fd / math::sqrt_pi;
}

// Returns the Fermi-Dirac integral of order 1/2 [Fuk15a]
double fd_int_half(double x)
{
	double fd;

	if (x < -2)
	{
		double ex = std::exp(x);
		double t = ex * 7.38905609893065023;
		fd = ex * (.886226925452758014 -
				   ex *
					   (19894.4553386951666 +
						t * (4509.64329955948557 +
							 t * (303.461789035142376 +
								  t * (5.7574879114754736 + t * .00275088986849762610)))) /
					   (63493.915041308052 +
						t * (19070.1178243603945 +
							 t * (1962.19362141235102 + t * (79.250704958640158 + t)))));
	}
	else if (x < 0)
	{
		double s = -.5 * x;
		double t = 1 - s;
		fd = (149.462587768865243 +
			  t * (22.8125889885050154 +
				   t * (-.629256395534285422 +
						t * (9.08120441515995244 +
							 t * (3.35357478401835299 +
								  t * (-.473677696915555805 +
									   t * (-.467190913556185953 +
											t * (-.0880610317272330793 -
												 t * .00262208080491572673)))))))) /
			 (269.94660938022644 +
			  s * (343.6419926336247 +
				   s * (323.9049470901941 +
						s * (218.89170769294024 +
							 s * (102.31331350098315 +
								  s * (36.319337289702664 + s * (8.3317401231389461 + s)))))));
	}
	else if (x < 2)
	{
		double t = .5 * x;
		fd = (71652.717119215557 +
			  t * (134954.734070223743 +
				   t * (153693.833350315645 +
						t * (123247.280745703400 +
							 t * (72886.293647930726 +
								  t * (32081.2499422362952 +
									   t * (10210.9967337762918 +
											t * (2152.71110381320778 +
												 t * 232.906588165205042)))))))) /
			 (105667.839854298798 +
			  t * (31946.0752989314444 +
				   t * (71158.788776422211 +
						t * (15650.8990138187414 +
							 t * (13521.8033657783433 +
								  t * (1646.98258283527892 +
									   t * (618.90691969249409 +
											t * (-3.36319591755394735 + t))))))));
	}
	else if (x < 5)
	{
		double t = .3333333333333333333 * (x - 2);
		fd = (23744.8706993314289 +
			  t * (68257.8589855623002 +
				   t * (89327.4467683334597 +
						t * (62766.3415600442563 +
							 t * (20093.6622609901994 +
								  t * (-2213.89084119777949 +
									   t * (-3901.66057267577389 - t * 948.642895944858861))))))) /
			 (9488.61972919565851 +
			  t * (12514.8125526953073 +
				   t * (9903.44088207450946 +
						t * (2138.15420910334305 +
							 t * (-528.394863730838233 +
								  t * (-661.033633995449691 + t * (-51.4481470250962337 + t)))))));
	}
	else if (x < 10.)
	{
		double t = .2 * x - 1;
		fd = (311337.452661582536 +
			  t * (1.11267074416648198e6 +
				   t * (1.75638628895671735e6 +
						t * (1.59630855803772449e6 +
							 t * (910818.935456183774 +
								  t * (326492.733550701245 +
									   t * (65507.2624972852908 + t * 4809.45649527286889))))))) /
			 (39721.6641625089685 +
			  t * (86424.7529107662431 +
				   t * (88163.7255252151780 +
						t * (50615.7363511157353 +
							 t * (17334.9774805008209 +
								  t * (2712.13170809042550 + t * (82.2205828354629102 - t))))))) *
			 .999999999999999877;
	}
	else if (x < 20)
	{
		double t = .1 * x - 1;
		fd = (7.26870063003059784e6 +
			  t * (2.79049734854776025e7 +
				   t * (4.42791767759742390e7 +
						t * (3.63735017512363365e7 +
							 t * (1.55766342463679795e7 +
								  t * (2.97469357085299505e6 + t * 154516.447031598403)))))) /
			 (340542.544360209743 +
			  t * (805021.468647620047 +
				   t * (759088.235455002605 +
						t * (304686.671371640343 +
							 t * (39289.4061400542309 +
								  t * (582.426138126398363 + t * (11.2728194581586028 - t))))))) *
			 .999999999999999877;
	}
	else if (x < 40)
	{
		double t = .05 * x - 1;
		fd = (4.81449797541963104e6 +
			  t * (1.85162850713127602e7 +
				   t * (2.77630967522574435e7 +
						t * (2.03275937688070624e7 +
							 t * (7.41578871589369361e6 +
								  t * (1.21193113596189034e6 + t * 63211.9545144644852)))))) /
			 (80492.7765975237449 +
			  t * (189328.678152654840 +
				   t * (151155.890651482570 +
						t * (48146.3242253837259 +
							 t * (5407.08878394180588 + t * (112.195044410775577 - t)))))) *
			 .999999999999999877;
	}
	else
	{
		double w = 1 / (x * x);
		double s = 1 - 1600 * w;
		fd = x * std::sqrt(x) * .666666666666666667 *
			 (1 + w * (8109.79390744477921 + s * (342.069867454704106 + s * 1.07141702293504595)) /
					  (6569.98472532829094 + s * (280.706465851683809 + s)));
	}

	return fd * 2 / math::sqrt_pi;
}

// Returns the Fermi-Dirac integral of order 1 [Fuk15a]
double fd_int_one(double y)
{
	double fd;
	const auto x = -std::abs(y);
	if (x < -2)
	{
		const auto ex = std::exp(x);
		const auto t = ex * 7.38905609893065023e0;
		fd = ex * (1 - ex *
						   (22189.1070807945062 +
							t * (4915.92700908746777 +
								 t * (322.901386168881348 +
									  t * (5.9897442965804548 + t * 0.00397641173774375092)))) /
						   (88756.428323178025 +
							t * (25002.3197546553836 +
								 t * (2389.06277237306633 + t * (88.376214553692756 + t)))));
	}
	else
	{
		const auto s = -0.5 * x;
		const auto t = 1 - s;
		fd = (145.488167182330098 +
			  t * (251.392824471576922 +
				   t * (56.6537141912783024 +
						t * (17.9918985363509694 +
							 t * (20.1369115558099802 +
								  t * (7.09659390228556164 +
									   t * (0.199701180197912643 +
											t * (-0.403173132925886253 -
												 t * 0.0792966701498222697)))))))) /
			 (606.0757707716040 +
			  s * (374.1806357435014 +
				   s * (252.1367051536344 +
						s * (27.2746245830016 + s * (-61.57766112137513 +
													 s * (-53.72117554363975 +
														  s * (-25.678454878692950 +
															   s * (-7.1995819520154718 - s))))))));
	}

	if (y > 0)
		fd = -fd + (math::pi_squared / 6) + (0.5 * y * y);

	return fd;
}

// Returns the inverse Fermi-Dirac integral of order 1 [Fuk15a]
double inverse_fd_int_one(double x)
{
	throw 0;
	return x;
}

// Returns the inverse Fermi-Dirac integral of order 1/2
double inverse_fd_int_half(double x)
{
	x *= math::sqrt_pi / 2;

	if (x < 1.17683303804380831)
	{
		double t = x * .849738210666018375;
		double z = t * (156377.8333056294 + t * (48177.5705898287 + t * (5847.07218383812 + t * (335.3978079672194 + t * 7.84411868029912))))
			   / (117762.02905535089 + t * (-19007.26938370368 + t * (1376.2936928453140 + t * (-54.11372698481717 + t))));
		return std::log(z);
	}
	else if (x < 3.82993088157949761)
	{
		double t = .376917874490198033 * x - .443569407329314587;
		return (489.140447310410217 + t * (5335.07269317261966 + t * (20169.0736140442509 + t * (35247.8115595510907 + t * (30462.3668614714761
			+ t * (12567.9032426128967 + t * (2131.86789357398657 + t * 93.6520172085419439)))))))
			/ (656.826207643060606 + t * (4274.82831051941605 + t * (10555.7581310151498 + t * (12341.8742094611883 + t * (6949.18854413197094
			+ t * (1692.19650634194002 + t * (129.221772991589751 + t)))))));
	}
	else if (x < 13.3854493161866553)
	{
		double t = .104651569335924949 * x - .400808277205416960;
		return (1019.84886406642351 + t * (9440.18255003922075 + t * (33947.6616363762463 + t * (60256.7280980542786 + t * (55243.0045063055787
																															+ t * (24769.8354802210838 + t * (4511.77288617668292 + t * 211.432806336150141)))))))
			/ (350.502070353586442 + t * (2531.06296201234050 + t * (6939.09850659439245 + t * (9005.40197972396592 + t * (5606.73612994134056
																														   + t * (1488.76634564005075 + t * (121.537028889412581 + t)))))));
	}
	else if (x < 53.2408277860982205)
	{
		double t = .0250907164450825724 * x - .335850513282463787;
		return (11885.8779398399498 + t * (113220.250825178799 + t * (408524.373881197840 + t * (695674.357483475952 + t * (569389.917088505552
			+ t * (206433.082013681440 + t * (27307.2535671974100 + t * 824.430826794730740)))))))
			/ (1634.40491220861182 + t * (12218.1158551884025 + t * (32911.7869957793233 + t * (38934.6963039399331 + t * (20038.8358438225823
		    + t * (3949.48380897796954 + t * (215.607404890995706 + t)))))));
	}
	else if (x < 188.411871723022843)
	{
		double t = .00739803415638806339 * x - .393877462475929313;
		return (11730.7011190435638 + t * (99421.7455796633651 + t * (327706.968910706902 + t * (530425.668016563224 + t * (438631.900516555072
			+ t * (175322.855662315845 + t * (28701.9605988813884 + t * 1258.20914464286403)))))))
			/ (634.080470383026173 + t * (4295.63159860265838 + t * (10868.5260668911946 + t * (12781.6871997977069 + t * (7093.80732100760563
		    + t * (1675.06417056300026 + t * (125.750901817759662 + t)))))));
	}
	else
	{
		double s = 1080.13412050984017 * std::pow(x, -4. / 3.);
		double t = 1 - s;
		double z = (1.12813495144821933e7 + t * (420368.911157160874 + t * (1689.69475714536117 + t)))
			/ (s * (6088.08350831295857 + t * (221.445236759466761 + t * .718216708695397737)));
		return std::sqrt(z);
	}
}
}

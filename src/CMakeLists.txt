add_executable(PPIL_Paint_client
	#Header
	SocketDrawClient.hpp
	Visitors/VisitorShape.hpp
	Visitors/VisitorDrawNetwork.hpp
	Visitors/VisitorExportCustom.hpp
	Utils/Matrice2x2.hpp
	Utils/Vecteur2D.hpp
	Shapes/Circle.hpp
	Shapes/Polygon.hpp
	Shapes/Segment.hpp
	Shapes/Shape.hpp
	Shapes/Triangle.hpp

	#Source
	main.cpp
	Utils/Vecteur2D.cpp
)
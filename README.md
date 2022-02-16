# Projet PPIL : Paint

## Notes

Finalement pas de format binaire, trop complexe de rendre ça utilisable facilement, on utilise juste des string (bonus, on gagne de la place avec les doubles, en moyenne 3-5 octets
pour un double comparé à 8 octets fixe en binaire)

### Global struct for writing shapes

	All other informations specific to certain shapes are appended after the global struct
	Type is a letter (C for Circle, T for Triangle, etc)
	Color should be an int, rgb is way more flexible than using predefined values
	Point List double are space separated

	Type (char) | Color (char or int if rgb) | Point list (2 * N double)

	May be hard to implement : Shapes in group do not send the color field (all shapes inside a group inherit the group color)
	Maybe not a good idea afterall, server would need to handle groups, more processing and code complexity to save 1 byte per shape, not worth it

	Does groups need to be handled by the server? If no just loop through all shapes and ->visit(this)

	Group needs to be a shape, might waste 
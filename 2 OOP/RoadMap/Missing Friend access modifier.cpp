/*
From inside an assembly, Friend and Public do the same thing, hence, it's friendly to the developer. But if the class is used from an outside assembly, everything that is marked Friend won't be available, whereas Public will be.
The C# equivalent is internal. The name internal probably gives a better definition than Friend of it's intended use.
*/


/*
Protected Friend:
It is used to specifies that access is limited to the current assembly or types derived from the containing class.
*/
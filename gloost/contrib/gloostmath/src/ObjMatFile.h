
/*
                       ___                            __
                      /\_ \                          /\ \__
                   __ \//\ \     ___     ___     ____\ \  _\
                 /'_ `\ \ \ \   / __`\  / __`\  /  __\\ \ \/
                /\ \ \ \ \_\ \_/\ \ \ \/\ \ \ \/\__   \\ \ \_
                \ \____ \/\____\ \____/\ \____/\/\____/ \ \__\
                 \/___/\ \/____/\/___/  \/___/  \/___/   \/__/
                   /\____/
                   \_/__/

                   OpenGL framework for fast demo programming

                             http://www.gloost.org

    This file is part of the gloost framework. You can use it in parts or as
       whole under the terms of the GPL (http://www.gnu.org/licenses/#GPL).

            gloost is being created by Felix Wei�ig and Stephan Beck

     Felix Wei�ig (thesleeper@gmx.net), Stephan Beck (stephan@pixelstars.de)
*/



#ifndef GLOOST_OBJMATFILE_H
#define GLOOST_OBJMATFILE_H



/// gloost system includes
#include <gloostConfig.h>
#include <gloostMath.h>
#include <Material.h>
#include <SharedResource.h>


/// cpp includes
#include <string>
#include <map>



#define GLOOST_OBJMATFILE_DEFAULT_MATERIAL "gloost_default_material"


namespace gloost
{


  ///  reads *.mtl files ( Material definition of Wavefront Obj format )

class ObjMatFile : public SharedResource
{
	public:

    /// class constructor
    ObjMatFile();

    /// class destructor
	  ~ObjMatFile();


    /// ~
    bool load(const std::string& filePath);


    /// returns a Material Pointer for a name or 0 if the material was not found
    Material* getMaterial(const std::string& materialName);


    /// returns a map with the material names as key and a pointer to a Material as value
    std::map<std::string, gloost::Material*>& getMaterials();
    const std::map<std::string, gloost::Material*>& getMaterials() const;


    /// add a Material to this mat file
    void addMaterial(const std::string& name, Material* material);



	private:

	  std::string                              _filePath;
    std::map<std::string, gloost::Material*> _materialMap;

};


} // namespace gloost


#endif // GLOOST_OBJMATFILE_H


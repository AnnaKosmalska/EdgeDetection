/*!
 * \file
 * \brief 
 * \author Anna Wujek
 */

#ifndef DrawSomeEdges_HPP_
#define DrawSomeEdges_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"
#include "Types/Edges.hpp"
#include <opencv2/opencv.hpp>


namespace Processors {
namespace DrawSomeEdges {

/*!
 * \class DrawSomeEdges
 * \brief DrawSomeEdges processor class.
 *
 * 
 */
class DrawSomeEdges: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
    DrawSomeEdges(const std::string & name = "DrawSomeEdges");

	/*!
	 * Destructor
	 */
    virtual ~DrawSomeEdges();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	// Input data streams
	Base::DataStreamIn<cv::Mat> in_img;
	Base::DataStreamIn<Types::Edges> in_edges;

	// Output data streams
	Base::DataStreamOut<cv::Mat> out_img;

	// Handlers
	Base::EventHandler2 h_DrawContours;

	// Properties
    Base::Property<int> edgeNumber;
	
	// Handlers
	void DrawContours();

};

} //: namespace DrawSomeEdges
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("DrawSomeEdges", Processors::DrawSomeEdges::DrawSomeEdges)

#endif /* DrawSomeEdges_HPP_ */

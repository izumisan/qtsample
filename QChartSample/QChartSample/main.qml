import QtQuick 2.9
import QtQuick.Window 2.2

import jbQuick.Charts 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QChart.js - Line")

    Chart {
        anchors.fill: parent

        chartAnimated: true;
        chartAnimationEasing: Easing.InOutElastic;
        chartAnimationDuration: 2000;
        chartType: Charts.ChartType.LINE;

        Component.onCompleted: {
            // サンプルデータ in QChartGallery.js within QChart
            chartData = {
                labels: ["January","February","March","April","May","June","July"],
                datasets: [{
                        fillColor: "rgba(220,220,220,0.5)",
                        strokeColor: "rgba(220,220,220,1)",
                        pointColor: "rgba(220,220,220,1)",
                        pointStrokeColor: "#ffffff",
                        data: [65,59,90,81,56,55,40]
                    }, {
                        fillColor: "rgba(151,187,205,0.5)",
                        strokeColor: "rgba(151,187,205,1)",
                        pointColor: "rgba(151,187,205,1)",
                        pointStrokeColor: "#ffffff",
                        data: [28,48,40,19,96,27,100]
                    }]
            }
        }
    }
}

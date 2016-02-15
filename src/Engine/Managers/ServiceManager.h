//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_SERVICEMANAGER_H
#define SSIM_SERVICEMANAGER_H

class ServiceManager {
public:
    static ServiceManager& getInstance(){
        static ServiceManager instance;
        return instance;
    }

    void init();

    void registerServiceProvider();

private:
    //Singleton initialisation----------------------------------------------------
    ServiceManager(){}  //Keep the constructor and destructor private
    ~ServiceManager(){}

    ServiceManager(ServiceManager const&) = delete;   //Prevent us from using these
    void operator=(ServiceManager const&) = delete;
    //----------------------------------------------------------------------------
};


#endif //SSIM_SERVICEMANAGER_H

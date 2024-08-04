#ifndef DEVICEMANAGER_H
#define DEVICEMANAGER_H

#include "qdir.h"
#include "qlabel.h"
#include "utils.h"
#include <vector>
#include <unordered_set>
#include <string>
#include <optional>

struct DeviceInfo {
    std::string UUID;
    std::string Name;
    Version Version;
};

class DeviceManager {
public:
    static DeviceManager& getInstance();

    std::vector<DeviceInfo> loadDevices();

    int getCurrentDeviceIndex();
    void setCurrentDeviceIndex(int index);
    void resetCurrentDevice();

    const std::optional<std::string> getCurrentWorkspace() const;

    const std::optional<std::string> getCurrentUUID() const;
    const std::optional<Version> getCurrentVersion() const;
    const std::optional<std::string> getCurrentName() const;

    bool isDeviceAvailable();
    void setTweakEnabled(Tweak t, bool);
    bool isTweakEnabled(Tweak t);
    std::vector<Tweak> getEnabledTweaks();


    void applyTweaks(QLabel* statusLabel);
    void removeTweaks(QLabel *statusLabel, bool deepClean);
private:
    DeviceManager();
    ~DeviceManager();

    static DeviceManager instance;

    void setCurrentWorkspace(std::string);
    void configureWorkspace(std::string);

    std::optional<DeviceInfo> currentDevice;
    int currentDeviceIndex;
    std::vector<DeviceInfo> devices;
    bool deviceAvailable;

    std::unordered_set<Tweak> enabledTweaks;

    std::optional<std::string> currentWorkspace;

    bool restoreBackupToDevice(const std::string&, const std::string&);
};

#endif // DEVICEMANAGER_H
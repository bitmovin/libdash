function KeySystemHelper(availableKeySystems) {
    var supportedKeySystems = [ ];
    var unsupportedKeySystems = [ ];
    var numberOfKeySystemsToTest = 0;
    var supportedKeySystemNames = [ ];
    var checkKeySystemFun = undefined;
    var video = undefined;

    var getSupportedKeySystemNames = function (callback) {
        video = document.createElement('video');
        checkKeySystemFun = getCheckKeySystemFun();
        if (availableKeySystems && checkKeySystemFun) {
            for (var keySystem in availableKeySystems) {
                if (!availableKeySystems.hasOwnProperty(keySystem)) continue;
                for (var idx = 0; idx < availableKeySystems[keySystem].length; idx++) {
                    checkKeySystemFun(availableKeySystems[keySystem][idx], keySystem);
                    numberOfKeySystemsToTest++;
                }
            }
            waitForKeySystemNames(callback);
        } else {
            callback(['nodrm']);
        }
    };

    var getCheckKeySystemFun = function() {
        if (window.navigator.requestMediaKeySystemAccess && typeof window.navigator.requestMediaKeySystemAccess === 'function') {
            return isKeySystemSupportedEME;
        } else if (window.MSMediaKeys && typeof window.MSMediaKeys === 'function') {
            return isKeySystemSupportedMS;
        } else if (video.webkitGenerateKeyRequest && typeof video.webkitGenerateKeyRequest === 'function') {
            return isKeySystemSupportedWebkit;
        } else {
            return undefined;
        }
    };

    var isKeySystemSupportedEME = function(keySystem, drmName) {
        var config = [{initDataTypes: ['cenc']}];
        window.navigator.requestMediaKeySystemAccess(keySystem, config).then(
            function(keySystemAccess) {
                supportedKeySystems.push(keySystemAccess.keySystem);
                if (supportedKeySystemNames.indexOf(drmName) < 0) {
                    supportedKeySystemNames.push(drmName);
                }
            }
        ).catch(function() {
                unsupportedKeySystems.push(keySystem);
            }
        );
    };

    var isKeySystemSupportedMS = function(keySystem, drmName) {
        if (MSMediaKeys.isTypeSupported(keySystem)) {
            supportedKeySystems.push(keySystem);
            if (supportedKeySystemNames.indexOf(drmName) < 0) {
                supportedKeySystemNames.push(drmName);
            }
        } else {
            unsupportedKeySystems.push(keySystem);
        }
    };

    var isKeySystemSupportedWebkit = function(keySystem, drmName) {
        if (video.canPlayType('video/mp4', keySystem)) {
            supportedKeySystems.push(keySystem);
            if (supportedKeySystemNames.indexOf(drmName) < 0) {
                supportedKeySystemNames.push(drmName);
            }
        } else {
            unsupportedKeySystems.push(keySystem);
        }
    };

    var waitForKeySystemNames = function (callback) {
        if (unsupportedKeySystems.length + supportedKeySystems.length < numberOfKeySystemsToTest) {
            setTimeout(function () {
                waitForKeySystemNames(callback);
            }, 250);
        } else {
            callback(supportedKeySystemNames, supportedKeySystems);
        }
    };

    return {
        getSupportedKeySystemNames: getSupportedKeySystemNames
    }
}
var ErrorMsgHelper = {

  getMissingKeyErrorMsg: function () {
    var a = document.createElement('a');
    a.href = 'https://portal.bitcodin.com/portal/bitdash-licensing/overview';
    a.target = '_blank';

    var div = document.createElement('div');
    div.style.padding = '25px';

    var h2 = document.createElement('h2');
    h2.className = 'ca-main';
    h2.style.marginBottom = '10px';
    h2.style.textAlign = 'center';
    h2.innerHTML = 'Player Key not set';

    var h3 = document.createElement('h3');
    h3.style.textAlign = 'center';
    h3.innerHTML = 'To set the player key please navigate to the directory <strong>sdk\\howto\\bitdash-player</strong> in this SDK and open the <strong>settings.js</strong> file using a text editor.' +
      '</br>Then replace "YOUR-KEY-HERE" with your player key provided in the <strong>Bitdash Licensing Overview</strong> section of the bitmovin portal.' +
      '</br></br>(Notice: Player without key works only on domain localhost)';

    div.appendChild(h2);
    div.appendChild(h3);
    a.appendChild(div);
    return a;
  }

};
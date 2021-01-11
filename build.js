const { execSync } = require('child_process');

const env = process.argv[2] !== '0'
  ? { npm_config_target: '12.20.0' }
  : {
    npm_config_target: '10.1.4',
    npm_config_dist_url: 'https://electronjs.org/headers',
    npm_config_runtime: 'electron'
  };

execSync('npm i', {
  stdio: 'inherit',
  env: {
    ...process.env,
    ...env
  }
});

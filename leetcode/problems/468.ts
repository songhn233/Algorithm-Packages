function validIPAddress(queryIP: string): string {
  const v6Reg = /^(?:[0-9a-fA-F]{1,4})(?:\:[0-9a-fA-F]{1,4}){7}$/
  const v4Reg =
    /^(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]\d|\d)(?:\.(?:25[0-5]|2[0-4]\d|1\d\d|[1-9]\d|\d)){3}$/
  return v4Reg.test(queryIP) ? 'IPv4' : v6Reg.test(queryIP) ? 'IPv6' : 'Neither'
}
